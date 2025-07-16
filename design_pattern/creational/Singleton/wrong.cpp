#include<iostream>

class Logger {
    public:
        void log(std::string message){
            std::cout << "Log: " << message << std::endl;
        }
    };

int main(){
    Logger logger1;
    Logger logger2;
    logger1.log("This is a log message.");
    logger2.log("This is another log message.");
    return 0;
}