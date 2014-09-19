#pragma once
#include <unordered_map>
#include "device/device.h"
#include "procedures/device_listener.h"
#include "common/common.h"

namespace minerva {

class DeviceFactory {
 public:
  DeviceFactory(DeviceListener*);
  ~DeviceFactory();
  uint64_t CreateCpuDevice();
#ifdef HAS_CUDA
  uint64_t CreateGpuDevice(int gid);
#endif
  Device* GetDevice(uint64_t id);
  
 private:
  uint64_t GenerateDeviceId();
  DeviceListener* listener_;
  std::unordered_map<uint64_t, Device*> device_storage_;
  DISALLOW_COPY_AND_ASSIGN(DeviceFactory);
};

}  // namespace minerva

