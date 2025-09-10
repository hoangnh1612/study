#include<iostream>
#include <vector>
// Component
class Task{
    public:
        virtual std::string getTitle() const = 0;
        virtual  void setTitle(const std::string& title) = 0;
        virtual void display() const = 0;
};

class SimpleTask : public Task {
    std::string title;
    public:
        SimpleTask(const std::string& title) : title(title) {}
        std::string getTitle() const override {
            return title;
        }
        void setTitle(const std::string& title) override {
            this->title = title;
        }
        void display() const override {
            std::cout << "Simple Task: " << title << std::endl;
        }
};

class CompositeTask : public Task {
    std::string title;
    std::vector<Task*> tasks;
    
    public:
        CompositeTask(const std::string& title) : title(title) {}
        
        void addTask(Task* task) {
            tasks.push_back(task);
        }
        
        void removeTask(Task* task) {
            tasks.erase(std::remove(tasks.begin(), tasks.end(), task), tasks.end());
        }
        
        std::string getTitle() const override {
            return title;
        }
        
        void setTitle(const std::string& title) override {
            this->title = title;
        }
        
        void display() const override {
            std::cout << "Composite Task: " << title << std::endl;
            for (const auto& task : tasks) {
                task->display();
            }
        }
};

int main() {
    SimpleTask task1("Task 1");
    SimpleTask task2("Task 2");
    
    CompositeTask composite("Composite Task");
    composite.addTask(&task1);
    composite.addTask(&task2);
    
    composite.display();
    
    return 0;
}