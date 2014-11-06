QT += widgets sql serialport network

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
    MotivosDeParadasDAO.h

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
    MotivosDeParadasDAO.cpp

FORMS += \
    TelaPrincipal.ui \
    TelaDeLogin.ui \
    Serial.ui \
    TelaDeParada.ui

RESOURCES += \
    Arquivos.qrc

