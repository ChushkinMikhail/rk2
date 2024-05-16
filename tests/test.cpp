#include <gtest/gtest.h>
#include <iostream>
#include <sstream>
#include "./../builder.cpp"

TEST(LOLGameDeviceTest, SetMouseTest) {
  jc::LOLGameDevice LOLBuilder;
  LOLBuilder.BuildMouse();
  EXPECT_EQ(LOLBuilder.Device().SetMouse("Logitech"), "Logitech");
}

TEST(DNFGameDeviceTest, SetKeyboardTest) {
  jc::DNFGameDevice DNFBuilder;
  DNFBuilder.BuildKeyboard();
  EXPECT_EQ(DNFBuilder.Device().SetKeyboard("Cherry"), "Cherry");
}

TEST(LifeTest, CreateDeviceTest) {
  jc::Life life;
  jc::LOLGameDevice LOLBuilder;
  jc::DeviceSuite LOLDevice = life.CreateDevice(LOLBuilder);
  
  EXPECT_EQ(LOLDevice.SetMouse("Logitech"), "Logitech");
  EXPECT_EQ(LOLDevice.SetKeyboard("Filco"), "Filco");
  EXPECT_EQ(LOLDevice.SetHeadphone("Sennheiser"), "Sennheiser");
}
