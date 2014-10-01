QT += widgets sql

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
    TelaSetup.h \
    TelaDeLogin.h

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
    TelaSetup.cpp \
    TelaDeLogin.cpp

FORMS += \
    TelaPrincipal.ui \
    TelaSetup.ui \
    TelaDeLogin.ui

RESOURCES += \
    Arquivos.qrc

