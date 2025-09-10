#include <iostream>

class ICommand
{
public:
    virtual void exec() = 0;
    virtual ~ICommand() = default;
};

class Device
{
public:
    void turnOn();
    void turnOff();
};

class TV : Device
{
public:
    void turnOn()
    {
        std::cout << "Turn on TV" << std::endl;
    }
    void turnOff()
    {
        std::cout << "Turn off TV" << std::endl;
    }
    void adjustChannel()
    {
        std::cout << "Adjust channel" << std::endl;
    }
};

class Radio : Device
{
public:
    void turnOn()
    {
        std::cout << "Turn on Radio" << std::endl;
    }
    void turnOff()
    {
        std::cout << "Turn off Radio" << std::endl;
    }
    void adjustVolume()
    {
        std::cout << "Adjust volume" << std::endl;
    }
};

class TurnOnCommand : ICommand
{
private:
    Device m_device;

public:
    TurnOnCommand(Device device)
    {
        m_device = device;
    }
    void exec() override
    {
        m_device.turnOn();
    }
};

class TurnOffCommand : ICommand
{
private:
    Device m_device;

public:
    TurnOffCommand(Device device)
    {
        m_device = device;
    }
    void exec() override
    {
        m_device.turnOff();
    }
};

class adjustVolume : ICommand
{
private:
    Radio m_radio;

public:
    adjustVolume(Radio radio)
    {
        m_radio = radio;
    }
    void exec() override
    {
        m_radio.adjustVolume();
    }
};

class adjustChannel : ICommand
{
private:
    TV m_tv;
public:
    adjustChannel(TV tv)
    {
        m_tv = tv;
    }
    void exec() override
    {
        m_tv.adjustChannel();
    }
};

int main()
{
    TV tv1;
    Radio radio1;
    adjustChannel adj(tv1);
    adjustVolume adj1(radio1);
    adj.exec();
    adj1.exec();
}