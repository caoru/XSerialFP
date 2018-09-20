
#include <stdio.h>
#include <fcntl.h>   /* File Control Definitions           */
#include <termios.h> /* POSIX Terminal Control Definitions */
#include <unistd.h>  /* UNIX Standard Definitions      */ 
#include <errno.h>   /* ERROR Number Definitions           */

#include "XSFPSerial.h"

XSFPSerial::XSFPSerial()
  : device_(""),
    descriptor_(-1),
    connected_(false)
{
}

XSFPSerial::~XSFPSerial()
{
}

bool XSFPSerial::Connect(const char *device)
{
  device_ = device;

  return Connect();
}

bool XSFPSerial::Connect(void)
{
  int fd = -1;
  int result;
  struct termios options;
  char buffer[16];
  char cmdrst[8] = {0x43, 0x4D, 0x44, 0x52, 0x53, 0x54, 0x00, 0x01};
  char cmdcon[8] = {0x43, 0x4D, 0x44, 0x43, 0x4F, 0x4E, 0x00, 0x01};
  char cmdfun[8] = {0x43, 0x4D, 0x44, 0x46, 0x55, 0x4E, 0x00, 0x01};
  char cmdver[8] = {0x43, 0x4D, 0x44, 0x56, 0x45, 0x52, 0x00, 0x01};

  if (device_.empty()) return false;

  fd = open(device_.c_str(), O_RDWR | O_NOCTTY | O_EXLOCK | O_NONBLOCK);
  if (fd < 0) return false;

  if (fcntl(fd, F_SETFL, 0) == -1) goto err;

  tcgetattr(fd, &options);

  cfmakeraw(&options);
  options.c_cflag &= ~PARENB;
  options.c_cflag &= ~CSTOPB;
  options.c_cflag &= ~CSIZE;
  options.c_cflag |= CS8;

  options.c_cflag |= HUPCL; // Turn on hangup on close
  options.c_cflag |= CLOCAL; // Set local mode on
  options.c_cflag |= CREAD; // Enable receiver
  options.c_lflag &= ~(ICANON /*| ECHO*/ | ISIG); // Turn off canonical mode and signals

  //options.c_cc[VMIN] = 1; // Wait for at least 1 character before returning
  //options.c_cc[VTIME] = 2; // Wait 200 milliseconds between bytes before returning from read
  options.c_cc[VMIN] = 0; // Wait for at least 1 character before returning
  options.c_cc[VTIME] = 0; // Wait 200 milliseconds between bytes before returning from read

  // Set baud rate
  cfsetspeed(&options, B115200);

  result = tcsetattr(fd, TCSANOW, &options);
  if (result < 0) goto err;

  tcflush(fd, TCIFLUSH);

  write(fd, cmdrst, 8);

  usleep(500000);

  write(fd, cmdcon, 8);
  read(fd, buffer, 8);

  write(fd, cmdfun, 8);
  read(fd, buffer, 8);

  write(fd, cmdver, 8);
  read(fd, buffer, 8);

  descriptor_ = fd;
  connected_ = true;

  return true;

err:
  close(fd);
  return false;
}

void XSFPSerial::Disconnect(void)
{
  char cmdrst[8] = {0x43, 0x4D, 0x44, 0x52, 0x53, 0x54, 0x00, 0x01};

  if (descriptor_ != -1)
  {
    write(descriptor_, cmdrst, 8);
    close(descriptor_);
    descriptor_ = -1;
  }
}

int XSFPSerial::Send(const void *buffer, int length)
{
  if (!connected_) return -1;

  return write(descriptor_, buffer, length);
}

int XSFPSerial::Receive(void *buffer, int length)
{
  if (!connected_) return -1;

  return read(descriptor_, buffer, length);
}

int XSFPSerialConnect(const char *port)
{
  int fd = -1;
  int result;
  struct termios options;
  char buffer[16];
  char cmdrst[8] = {0x43, 0x4D, 0x44, 0x52, 0x53, 0x54, 0x00, 0x01};
  char cmdcon[8] = {0x43, 0x4D, 0x44, 0x43, 0x4F, 0x4E, 0x00, 0x01};
  char cmdfun[8] = {0x43, 0x4D, 0x44, 0x46, 0x55, 0x4E, 0x00, 0x01};
  char cmdver[8] = {0x43, 0x4D, 0x44, 0x56, 0x45, 0x52, 0x00, 0x01};


  fd = open(port, O_RDWR | O_NOCTTY | O_EXLOCK | O_NONBLOCK);
  if (fd < 0) return -1;

  if (fcntl(fd, F_SETFL, 0) == -1) goto err;

  tcgetattr(fd, &options);

  cfmakeraw(&options);
  options.c_cflag &= ~PARENB;
  options.c_cflag &= ~CSTOPB;
  options.c_cflag &= ~CSIZE;
  options.c_cflag |= CS8;

  options.c_cflag |= HUPCL; // Turn on hangup on close
  options.c_cflag |= CLOCAL; // Set local mode on
  options.c_cflag |= CREAD; // Enable receiver
  options.c_lflag &= ~(ICANON /*| ECHO*/ | ISIG); // Turn off canonical mode and signals

  //options.c_cc[VMIN] = 1; // Wait for at least 1 character before returning
  //options.c_cc[VTIME] = 2; // Wait 200 milliseconds between bytes before returning from read
  options.c_cc[VMIN] = 0; // Wait for at least 1 character before returning
  options.c_cc[VTIME] = 0; // Wait 200 milliseconds between bytes before returning from read

  // Set baud rate
  cfsetspeed(&options, B115200);

  result = tcsetattr(fd, TCSANOW, &options);
  if (result < 0) goto err;

  tcflush(fd, TCIFLUSH);

  write(fd, cmdrst, 8);

  usleep(500000);

  write(fd, cmdcon, 8);
  read(fd, buffer, 8);

  write(fd, cmdfun, 8);
  read(fd, buffer, 8);

  write(fd, cmdver, 8);
  read(fd, buffer, 8);

  return fd;

err:
  close(fd);
  return -1;
}

void XSFPSerialDisconnect(int fd)
{
  close(fd);
}

int XSFPSerialSend(int fd, const void *buffer, int length)
{
  return write(fd, buffer, length);
}

int XSFPSerialReceive(int fd, void *buffer, int length)
{
  return read(fd, buffer, length);
}

