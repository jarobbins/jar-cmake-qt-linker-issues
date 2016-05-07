#include <QObject>

class TestClass1 : public QObject
{
	Q_OBJECT
	
public:
	TestClass1(QObject * parent = 0);

public slots:
	void doSomething();
};
