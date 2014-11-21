QT += widgets sql serialport network core

TEMPLATE = app

win32:DEFINES += _TTY_WIN_  WINVER=0x0501

win32:LIBS += -lsetupapi -lwsock32 -lws2_32

HEADERS += \
    Conexao.h \
    Cliente.h \
    Maquina.h \
    Usuario.h \
    OrdemDeProducao.h \
    Setup.h \
    Paradas.h \
    Producao.h \
    Apontamento.h \
    UsuarioDAO.h \
    MaquinaDAO.h \
    ClienteDAO.h \
    OrdemDeProducaoDAO.h \
    SetupDAO.h \
    ProducaoDAO.h \
    ParadasDAO.h \
    ApontamentoDAO.h \
    TelaPrincipal.h \
    TelaDeLogin.h \
    Botao.h \
    TelaDeSetup.h \
    Serial.h \
    TelaDeProducao.h \
    TelaDeParada.h \
    SerialDAO.h \
    MotivosDeParadas.h \
    MotivosDeParadasDAO.h \
    LibModBus/modbus-version.h \
    LibModBus/modbus-tcp-private.h \
    LibModBus/modbus-tcp.h \
    LibModBus/modbus-rtu-private.h \
    LibModBus/modbus-rtu.h \
    LibModBus/modbus-private.h \
    LibModBus/modbus.h \
    LibModBus/config.h

SOURCES += \
    Conexao.cpp \
    Main.cpp \
    Cliente.cpp \
    Maquina.cpp \
    Usuario.cpp \
    OrdemDeProducao.cpp \
    Setup.cpp \
    Paradas.cpp \
    Producao.cpp \
    Apontamento.cpp \
    UsuarioDAO.cpp \
    MaquinaDAO.cpp \
    ClienteDAO.cpp \
    OrdemDeProducaoDAO.cpp \
    SetupDAO.cpp \
    ProducaoDAO.cpp \
    ParadasDAO.cpp \
    ApontamentoDAO.cpp \
    TelaPrincipal.cpp \
    TelaDeLogin.cpp \
    Botao.cpp \
    TelaDeSetup.cpp \
    Serial.cpp \
    TelaDeProducao.cpp \
    TelaDeParada.cpp \
    SerialDAO.cpp \
    MotivosDeParadas.cpp \
    MotivosDeParadasDAO.cpp \
    LibModBus/modbus-tcp.c \
    LibModBus/modbus-rtu.c \
    LibModBus/modbus-data.c \
    LibModBus/modbus.c

FORMS += \
    TelaPrincipal.ui \
    TelaDeLogin.ui \
    Serial.ui \
    TelaDeParada.ui

RESOURCES += \
    Arquivos.qrc

