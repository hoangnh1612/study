#include<iostream>

class Computer {
    public:
        void setRam(int ram)
        {
            m_ram = ram;
        }
        void setCPU(std::string cpu)
        {
            m_cpu = cpu;
        }
        void setGPU(std::string gpu)
        {
            m_gpu = gpu;
        }
        void display()
        {
            std::cout<<"RAM: "<<m_ram;
            std::cout<<"CPU: "<<m_cpu;
            std::cout<<"GPU: "<<m_gpu;
        }
    private:
        int m_ram;
        std::string m_cpu;
        std::string m_gpu;
};


class BuilderPipeline{
    public:
        virtual void buildCPU(std::string cpu) = 0;
        virtual void buildGPU(std::string gpu) = 0;
        virtual void buildComputer(int ram, std::string cpu, std::string gpu) = 0;
        Computer getComputer() {
            return m_comp;
        }
    private:
        Computer m_comp;
};
class BuildMycomp : public BuilderPipeline {
    public:
        void buildCPU(std::string cpu) override {
            m_comp.setCPU(cpu);
        }
        void buildGPU(std::string gpu) override {
            m_comp.setGPU(gpu);
        }
        void buildComputer(int ram, std::string cpu, std::string gpu) override {
            m_comp.setRam(ram);
            m_comp.setCPU(cpu);
            m_comp.setGPU(gpu);
        }
        void display() {
            m_comp.display();
        }
    private:
        Computer m_comp;
};


class Director {
    public:
        void buildComputer(int ram, std::string cpu, std::string gpu){
            m_builder.buildComputer(ram, cpu, gpu);
        }
        void displayComputer() {
            m_builder.display();
        }
    private:
        BuildMycomp m_builder;
    };

int main() {
    Director director;
    director.buildComputer(16, "Intel i7", "NVIDIA RTX 3080");
    director.displayComputer();
    return 0;
}



