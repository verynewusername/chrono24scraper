#include "main.ih"

void readyCheck()
{
    std::cout << "Do you want to start the scraper? (y/n): ";
    char answer;

    std::cin >> answer;

    while (answer != 'y' && answer != 'n' && answer != 'Y' && answer != 'N')
    {
        std::cout << "Please enter y or n: ";
        std::cin >> answer;
    }

    if (answer == 'y' || answer == 'Y') {
        // Get the starting time
        std::chrono::time_point<std::chrono::system_clock> start = std::chrono::system_clock::now();

        // Convert the starting time to a time_t and format as a date
        std::time_t start_time = std::chrono::system_clock::to_time_t(start);
        std::cout << "LOG: Starting at " << std::ctime(&start_time);
            
        run();

        // Get the ending time
        std::chrono::time_point<std::chrono::system_clock> end = std::chrono::system_clock::now();

        // Convert the ending time to a time_t and format as a date
        std::time_t end_time = std::chrono::system_clock::to_time_t(end);
        std::cout << "LOG: Ending at " << std::ctime(&end_time);

        // Calculate the elapsed time
        std::chrono::duration<double> elapsed_seconds = end - start;
        std::cout << "LOG: Elapsed time: " << elapsed_seconds.count() << " seconds" << std::endl;
    } else
        std::cout << "Aborted!\n";
}
