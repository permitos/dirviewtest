#include "dirview.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    DirView dirView;
    dirView.show();

    return app.exec();
}
