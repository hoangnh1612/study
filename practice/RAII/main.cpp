#include<iostream>

class Resource{
    public:
        Resource(){
            std::cout<<"Resource acquired"<<std::endl;
            m_data = new int[100];
        }

        int *getData(){
            return m_data;
        }

        void setData(int *data){
            m_data = data;
        }

        void printData(){
            for(int i=0; i<100; i++)
            {
                std::cout<<m_data[i]<<" ";
            }
            std::cout<<std::endl;
        }

        ~Resource(){
            std::cout<<"Resource released"<<std::endl;
            if(m_data)
                delete[] m_data;
                m_data = nullptr;
        }
    private:
        int *m_data;
};

int main()
{
    Resource r1;
    auto data = r1.getData();
    for(int i=0; i<100; i++)
    {
        data[i] = i;
    }

    Resource r2;
    r2.setData(data);
    r2.printData();
}