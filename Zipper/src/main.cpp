#include <Zipper/Zipper.hpp>
#include <Zipper/Unzipper.hpp>
#include <iostream>
#include <vector>

//------------------------------------------------------------------------------
int main()
{
    zipper::Zipper zipper("ziptest.zip");
    zipper.add("somefile.txt");
    zipper.close();
    
    zipper::Unzipper unzipper("ziptest.zip");
    std::vector<zipper::ZipEntry> entries = unzipper.entries();
    for (auto& it: unzipper.entries())
    {
        std::cout << it.name << std::endl;
    }
    unzipper.extractAll("/tmp");
    unzipper.close();

    return EXIT_SUCCESS;
}
