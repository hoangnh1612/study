#include<iostream>
#include<memory>
class Logger {
    public:
        void log(std::string message){
            std::cout << "Log: " << message << std::endl;
        }
        std::shared_ptr<Logger> getInstance() {
            if(!instance) {
                instance = std::make_shared<Logger>();
            }
            return instance;
        }
    private:
        std::shared_ptr<Logger> instance = nullptr;
    };

int main() {
    auto logger1 = Logger().getInstance();
    auto logger2 = Logger().getInstance();
    logger1->log("This is a log message.");
    logger2->log("This is another log message.");
    return 0;
}
