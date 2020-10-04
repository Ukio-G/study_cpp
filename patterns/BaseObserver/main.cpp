#include <iostream>
#include <vector>
#include <memory>
#include <cstring>

#define BUFFER_SIZE 1024

class IObserver {
public:
    virtual void update(void * data, uint64_t size) = 0;
};

using IObserverSPtr = std::shared_ptr<IObserver>;

class IPublisher {
public:
    virtual void notify(void * data, uint64_t size) = 0;
    virtual void addSubscriber(IObserverSPtr) = 0;
    virtual void removeSubscriber(IObserverSPtr) = 0;
    virtual std::vector<IObserverSPtr>::iterator isSubscribed(IObserverSPtr possible_observer) = 0;
};

class Host : public IObserver {
public:
    Host() = default;
    Host(uint64_t host_id) : host_id(host_id) { };
    char buffer[BUFFER_SIZE];
    uint64_t buffer_size = 0;
    uint64_t host_id;
    void update(void *data, uint64_t size) override {
        std::cout << "I'm host " << host_id << ", and I get something\n";
        memcpy(buffer, data, size);
        buffer_size = size;
    }

    void print_buffer() {
        char str[buffer_size+1];
        memcpy(str, buffer, buffer_size);
        str[buffer_size] = '\0';
        std::cout << str << '\n';
    }
};

class Router : public IPublisher, public IObserver {
public:
    Router() = default;
    Router(Router & other) = default;

    char buffer[BUFFER_SIZE];
    uint64_t buffer_size = 0;

    void notify(void * data, uint64_t size) override {
        for (const auto &item : m_subscribers)
            ((Host*)item.get())->update(data, size);
    }

    void update(void * data, uint64_t size) {
        std::cout << "I'm router, and I get something\n";
        memcpy(buffer, data, size);
        buffer_size = size;
    }

    void print_buffer() {
        char str[buffer_size+1];
        memcpy(str, buffer, buffer_size);
        str[buffer_size] = '\0';
        std::cout << str << '\n';
    }

    void addSubscriber(IObserverSPtr observer) override {
        if(isSubscribed(observer) == m_subscribers.end())
            m_subscribers.push_back(observer);
    }

    void removeSubscriber(IObserverSPtr observer) override {
        auto erase_iterator = isSubscribed(observer);
        if(erase_iterator != m_subscribers.end())
            m_subscribers.erase(erase_iterator);
    }

    std::vector<IObserverSPtr>::iterator isSubscribed(IObserverSPtr possible_observer) override {
        auto last_iter = m_subscribers.end();
        for(auto iterator = m_subscribers.begin(); iterator != last_iter; iterator++){
            if(iterator->get() == possible_observer.get())
                return iterator;
        }
        return last_iter;
    }
private:
    std::vector<IObserverSPtr> m_subscribers;
};

int main() {
    Router router1;
    using HostSPtr = std::shared_ptr<Host>;

    auto host1 = HostSPtr(new Host(10)) ;
    auto host2 = HostSPtr(new Host(20)) ;
    auto host3 = HostSPtr(new Host(30)) ;

    router1.addSubscriber(host1);
    router1.addSubscriber(host1);   // No effect
    router1.addSubscriber(host2);

    router1.notify((void*)"123456",6);

    router1.removeSubscriber(host2);
    router1.removeSubscriber(host2);    // No effect
    router1.notify((void*)"123456",6);

    host1->print_buffer();

    auto sharedRouter = std::shared_ptr<Router>(new Router);
    router1.addSubscriber(sharedRouter);

    router1.notify((void*)"New router appended",19);

    sharedRouter->print_buffer();
    return 0;
}
