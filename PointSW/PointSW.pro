QT += widgets sql serialport network core

TEMPLATE = app

win32:DEFINES += _TTY_WIN_  WINVER=0x0501

win32:LIBS += -lsetupapi -lwsock32 -lws2_32

HEADERS += \
    Dados/Conexao.h \
    Dados/Cliente.h \
    Dados/Maquina.h \
    Dados/Usuario.h \
    Dados/OrdemDeProducao.h \
    Dados/Setup.h \
    Dados/Paradas.h \
    Dados/Producao.h \
    Dados/Apontamento.h \
    DAO/UsuarioDAO.h \
    DAO/MaquinaDAO.h \
    DAO/ClienteDAO.h \
    DAO/OrdemDeProducaoDAO.h \
    DAO/SetupDAO.h \
    DAO/ProducaoDAO.h \
    DAO/ParadasDAO.h \
    DAO/ApontamentoDAO.h \
    TelaPrincipal.h \
    TelaDeLogin.h \
    Dados/Botao.h \
    TelaDeSetup.h \
    Serial.h \
    TelaDeProducao.h \
    TelaDeParada.h \
    SerialDAO.h \
    Dados/MotivosDeParadas.h \
    DAO/MotivosDeParadasDAO.h \
    LibModBus/modbus-version.h \
    LibModBus/modbus-tcp-private.h \
    LibModBus/modbus-tcp.h \
    LibModBus/modbus-rtu-private.h \
    LibModBus/modbus-rtu.h \
    LibModBus/modbus-private.h \
    LibModBus/modbus.h \
    LibModBus/config.h

SOURCES += \
    Dados/Conexao.cpp \
    Main.cpp \
    Dados/Cliente.cpp \
    Dados/Maquina.cpp \
    Dados/Usuario.cpp \
    Dados/OrdemDeProducao.cpp \
    Dados/Setup.cpp \
    Dados/Paradas.cpp \
    Dados/Producao.cpp \
    Dados/Apontamento.cpp \
    DAO/UsuarioDAO.cpp \
    DAO/MaquinaDAO.cpp \
    DAO/ClienteDAO.cpp \
    DAO/OrdemDeProducaoDAO.cpp \
    DAO/SetupDAO.cpp \
    DAO/ProducaoDAO.cpp \
    DAO/ParadasDAO.cpp \
    DAO/ApontamentoDAO.cpp \
    TelaPrincipal.cpp \
    TelaDeLogin.cpp \
    Dados/Botao.cpp \
    TelaDeSetup.cpp \
    Serial.cpp \
    TelaDeProducao.cpp \
    TelaDeParada.cpp \
    DAO/SerialDAO.cpp \
    Dados/MotivosDeParadas.cpp \
    DAO/MotivosDeParadasDAO.cpp \
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

