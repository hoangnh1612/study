#include<iostream>
#include<vector>
class Memento{
    private:
        std::string content;
    public:
        Memento(std::string content){
            this->content = content;
        }
        std::string getSavedContent() {
            return content;
        }       
};
class Document{
    private:
        std::string content;
    public:
        Document(){}
        void write(std::string s)
        {
            content = s;
        }
        std::string getContent()
        {
            return content;
        }
        Memento createMemento()
        {
            return Memento(content);
        }
        void restoreFromMemento(Memento m)
        {
            this->content = m.getSavedContent();
        }
};



class History{
    private:
        std::vector<Memento> list;
    public:
        History(){}
        void addMemento(Memento m){
            list.push_back(m);
        }
        Memento getMemento(int index){
            if(index >=list.size())
            {
                std::cout<<"Out of range"<<std::endl;
                return Memento("");
            }
            return list[index];
        }
    };

int main()
{
    Document d1;
    History h;
    d1.write("State1");
    h.addMemento(d1.createMemento());
    d1.write("State2");
    h.addMemento(d1.createMemento());
    d1.write("State3");
    h.addMemento(d1.createMemento());
    d1.restoreFromMemento(h.getMemento(1));
    std::cout<<d1.getContent()<<std::endl;
}

