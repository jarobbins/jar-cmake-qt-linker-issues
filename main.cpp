#include <QCoreApplication>
#include "TestLibrary1.hpp"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
	
	TestClass1 * tc1 = new TestClass1(0);
	
    return a.exec();
}
