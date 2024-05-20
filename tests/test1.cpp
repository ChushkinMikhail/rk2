#include <memory>
#include <string_view>
#include <iostream>
#include <sstream>

namespace jc {

class DeviceSuite {
 public:
  void SetMouse(std::string_view) {}
  void SetKeyboard(std::string_view) {}
  void SetHeadphone(std::string_view) {}
};

class GameDevice {
 public:
  virtual void BuildMouse() = 0;
  virtual void BuildKeyboard() = 0;
  virtual void BuildHeadphone() = 0;
  virtual DeviceSuite& Device() const = 0;
  virtual ~GameDevice() = default;
};

class LOLGameDevice : public GameDevice {
 public:
  LOLGameDevice() : device_(std::make_unique<DeviceSuite>()) {}
  void BuildMouse() override { device_->SetMouse("Logitech"); }
  void BuildKeyboard() override { device_->SetKeyboard("Filco"); }
  void BuildHeadphone() override { device_->SetHeadphone("Sennheiser"); }
  DeviceSuite& Device() const override { return *device_; }
 private:
  std::unique_ptr<DeviceSuite> device_;
};

class DNFGameDevice : public GameDevice {
 public:
  DNFGameDevice() : device_(std::make_unique<DeviceSuite>()) {}
  void BuildMouse() override { device_->SetMouse("Razer"); }
  void BuildKeyboard() override { device_->SetKeyboard("Cherry"); }
  void BuildHeadphone() override { device_->SetHeadphone("Beyerdynamic"); }
  DeviceSuite& Device() const override { return *device_; }
 private:
  std::unique_ptr<DeviceSuite> device_;
};

class Life {
 public:
  DeviceSuite& CreateDevice(GameDevice& builder) {
    builder.BuildMouse();
    builder.BuildKeyboard();
    builder.BuildHeadphone();
    return builder.Device();
  }
};

} 

void testLOLGameDevice() {
  jc::Life life;
  jc::LOLGameDevice LOLBuilder;

  jc::DeviceSuite LOLDevice = life.CreateDevice(LOLBuilder);
  
  if (&LOLDevice != nullptr){
  	std::cout<<"Succecfull test1"<<std::endl;
  }
  else std::cout<<"Unuccecfull test1"<<std::endl;
}

int main() {
  testLOLGameDevice();
  return 0;
}
