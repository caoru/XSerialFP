#ifndef _XSFPSERIAL_H_
#define _XSFPSERIAL_H_

#include <iostream>

class XSFPSerial
{
public:
  XSFPSerial();
  ~XSFPSerial();

public:
  std::string device(void) { return device_; }
  void device(char *device) { device_ = device; }

  int descriptor(void) { return descriptor_; }
  void descriptor(int descriptor) { descriptor_ = descriptor; }

  bool connected(void) { return connected_; }

public:
  bool Connect(void);
  bool Connect(const char *device);
  void Disconnect(void);

  int Send(const void *buffer, int length);
  int Receive(void *buffer, int length);

private:
  std::string device_;
  int descriptor_;
  bool connected_;
};

int XSFPSerialConnect(const char *port);
void XSFPSerialDisconnect(int fd);

int XSFPSerialSend(int fd, const void *buffer, int length);
int XSFPSerialReceive(int fd, void *buffer, int length);

#endif /* _XSFPSERIAL_H_ */

