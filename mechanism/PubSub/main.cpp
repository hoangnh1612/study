#include <iostream>
#include <unordered_map>
#include <string>
#include <queue>
#include <vector>

class Subscriber;

class Message
{
    std::string m_message;

public:
    Message(std::string message) : m_message(message) {}
    std::string getMessage() const { return m_message; }
};

class Broker {
    std::unordered_map<std::string, std::queue<Message*>> topics;
    std::unordered_map<std::string, std::vector<Subscriber*>> subscriber;
    public:
        void subscribe(const std::string &topic, Subscriber *sub);
        void publish(const std::string &topic, Message *message);
};

class Publisher{
    Broker *m_broker;
    public:
        Publisher(Broker &broker) : m_broker(&broker){}
        void publish(const std::string &topic, Message *message){
            m_broker->publish(topic, message);
        }
};

class Subscriber {
    Broker *m_broker;
    public:
        Subscriber(Broker &broker) : m_broker(&broker) {}
        void subscribe(const std::string &topic){
            m_broker->subscribe(topic, this);
        }
        void receive(const Message *message, const std::string &topic) {
            std::cout << "Received message: " << message->getMessage() << ", from topic: " << topic << "\n";
        }
};

void Broker::subscribe(const std::string &topic, Subscriber *sub) {
    subscriber[topic].push_back(sub);
}

void Broker::publish(const std::string &topic, Message *message)
{
    topics[topic].push(message);
    for (auto &sub: subscriber[topic])
        sub->receive(message, topic);
}

int main()
{
    Message *mess1 = new Message("This is mess1");
    Broker b;
    Subscriber sub1(b);
    Subscriber sub2(b);
    sub1.subscribe("test_topic");
    sub2.subscribe("test_topic");
    
    Publisher pub1(b);
    pub1.publish("test_topic", mess1);
}