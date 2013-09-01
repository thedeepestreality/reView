#-------------------------------------------------
#
# Project created by QtCreator 2013-08-15T01:05:28
#
#-------------------------------------------------

QT       += core network testlib

QT       -= gui

TARGET = YetAnotherTest
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    myserver.cpp

HEADERS += \
    myserver.h

unix {
    INCLUDEPATH += /usr/include/opencv2/
    LIBS += -LC:/usr/lib/ \
        -lopencv_core \
        -lopencv_highgui \
        -lopencv_imgproc \
        -lopencv_features2d \
        -lopencv_calib3d
}

win32 {

  OPENCV_PATH = d:/Work/opencv


    INCLUDEPATH += \
        $$OPENCV_PATH/build/include \

          LIBS += \
            -L$$OPENCV_PATH\build\x86\vc9\lib \
            -lopencv_core242d \
            -lopencv_highgui242d \
            -lopencv_video242d \
            -lopencv_ml242d \
            -lopencv_legacy242d \
            -lopencv_imgproc242d \
            -lopencv_flann242d \
            -lopencv_features2d242d \
            -lopencv_contrib242d \
            -L$$OPENCV_PATH\build\x86\vc9\staticlib \
            -llibjasperd \
            -llibjpegd \
            -llibpngd \
            -llibtiffd \
            -lzlibd \
            -lvfw32 \
            -lole32 \

      }
