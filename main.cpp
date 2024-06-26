#include <QApplication>
#include <QWidget>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QWidget window;
    window.resize(1000, 1000);
    window.setWindowTitle("Simple Qt Application");
    window.show();

    return app.exec();`	
}
