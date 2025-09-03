// #include <chrono>
// #include <thread>
// #include <iostream>
// #include <future>

// void parallelingTask()
// {
//     std::cout << "Start exec paralleling task" << std::endl;
//     std::this_thread::sleep_for(std::chrono::seconds(10));
//     std::cout << "Finish parallel task" << std::endl;
// }

// void mainTask()
// {
//     while (true)
//     {
//         std::cout << "Exec main task" << std::endl;
//         std::this_thread::sleep_for(std::chrono::seconds(1));
//     }
// }

// int main()
// {

//     std::async(std::launch::async, mainTask);
//     if (std::cin.get() == '\n')
//     {
//         std::async(std::launch::async, parallelingTask);
//     }
// }

#include <chrono>
#include <thread>
#include <iostream>
#include <future>
#include <atomic>
#include <thread>

void parallelingTask()
{
    std::cout << "Start exec paralleling task" << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(10));
    std::cout << "Finish parallel task" << std::endl;
}

void mainTask(std::atomic<bool>& stopFlag)
{
    while (!stopFlag)
    {
        std::cout << "Exec main task" << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}

int main()
{
    std::atomic<bool> stopFlag{false};

    // Start the main task in a separate thread
    std::thread mainThread(mainTask, std::ref(stopFlag));

    std::string input;
    while (true)
    {
        std::getline(std::cin, input);
        if (input.empty())  // Pressed only Enter
        {
            std::async(std::launch::async, parallelingTask);
        }
        else if (input == "q")  // Allow quitting cleanly
        {
            break;
        }
    }

    // Stop the main task and join the thread
    stopFlag = true;
    mainThread.join();
    return 0;
}
