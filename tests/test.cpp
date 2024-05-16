#include <gtest/gtest.h>
#include <iostream>
#include <sstream>
#include "./../builder.cpp"

TEST(LOLGameDeviceTest, SetMouseTest) {
  jc::LOLGameDevice LOLBuilder;
  LOLBuilder.BuildMouse();
  EXPECT_EQ(LOLBuilder.Device().GetMouse(), "Logitech");
}

TEST(DNFGameDeviceTest, SetKeyboardTest) {
  jc::DNFGameDevice DNFBuilder;
  DNFBuilder.BuildKeyboard();
  EXPECT_EQ(DNFBuilder.Device().GetKeyboard(), "Cherry");
}

TEST(LifeTest, CreateDeviceTest) {
  jc::Life life;
  jc::LOLGameDevice LOLBuilder;
  jc::DeviceSuite LOLDevice = life.CreateDevice(LOLBuilder);
  
  EXPECT_EQ(LOLDevice.GetMouse(), "Logitech");
  EXPECT_EQ(LOLDevice.GetKeyboard(), "Filco");
  EXPECT_EQ(LOLDevice.GetHeadphone(), "Sennheiser");
}
