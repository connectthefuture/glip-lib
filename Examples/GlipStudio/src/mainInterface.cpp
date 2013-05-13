#include "mainInterface.hpp"

// MainWindow
	MainWindow::MainWindow(void)
	 : QWidget(NULL), layout(this), codeEditors(this)
	{
		QObject::connect(&codeEditors, SIGNAL(requireRefresh()), this, SLOT(refreshPipeline()));

		layout.addWidget(&codeEditors);
		resize(640,480);
		show();
	}

	MainWindow::~MainWindow(void)
	{

	}

	void MainWindow::refreshPipeline(void)
	{
		std::cout << "Refreshing code : " << std::endl;
		std::cout << codeEditors.getCurrentCode() << std::endl;
	}

// GlipStudio
	GlipStudio::GlipStudio(int& argc, char** argv)
	 : QApplication(argc, argv), mainWindow(NULL)
	{
		const QString 	stylesheetFilename = "stylesheet.css";
		QFile 		stylesheetFile(stylesheetFilename);
			
		if(!stylesheetFile.open(QIODevice::ReadOnly | QIODevice::Text))
		{
			QMessageBox::information(NULL, tr("GlipStudio::GlipStudi - Error :"), tr("The style sheet \"%1\" could not be loaded.").arg(stylesheetFile.fileName()));
			throw Exception("GlipStudio::GlipStudio - The style sheet \"" + stylesheetFile.fileName().toStdString()  + "\" could not be loaded.", __FILE__, __LINE__); 
		}

		QTextStream 	stylesheetStream(&stylesheetFile);
		QString 	stylesheet = stylesheetStream.readAll();

		// Set style : 
		QApplication::setStyleSheet(stylesheet);

		mainWindow = new MainWindow();
	}

	GlipStudio::~GlipStudio(void)
	{
		delete mainWindow;
	}
 