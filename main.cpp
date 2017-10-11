//#include <Qt3DQuickExtras/qt3dquickwindow.h>
//#include <Qt3DQuick/QQmlAspectEngine>
//#include <QGuiApplication>
//#include <QQmlEngine>
//#include <QQmlContext>
#include <QGuiApplication>
#include <QQuickView>
#include <QQmlContext>
#include <QOpenGLContext>

int main(int argc, char *argv[])
{
//    QGuiApplication app(argc, argv);
//    Qt3DExtras::Quick::Qt3DQuickWindow view;

//    // Expose the window as a context property so we can set the aspect ratio
//    view.engine()->qmlEngine()->rootContext()->setContextProperty("_window", &view);
//    view.setSource(QUrl("qrc:/main.qml"));
//    view.show();

//    return app.exec();

    QGuiApplication app(argc, argv);

    QSurfaceFormat format;
    if (QOpenGLContext::openGLModuleType() == QOpenGLContext::LibGL) {
        format.setVersion(3, 2);
        format.setProfile(QSurfaceFormat::CoreProfile);
    }
    format.setDepthBufferSize(24);
    format.setStencilBufferSize(8);
    format.setSamples(4);

//    NetworkController networkController;

    QQuickView view;
    view.setFormat(format);
//    view.rootContext()->setContextProperty("networkController", &networkController);
//    view.engine()->qmlEngine()->rootContext()->setContextProperty("_window", &view);
    view.rootContext()->setContextProperty("_window", &view);
    view.setResizeMode(QQuickView::SizeRootObjectToView);
    view.setSource(QUrl("qrc:/main.qml"));
    view.setColor("#000000");
    view.show();

    return app.exec();


}
