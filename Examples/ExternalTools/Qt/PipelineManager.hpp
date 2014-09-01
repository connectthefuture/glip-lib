/* ************************************************************************************************************* */
/*                                                                                                               */
/*     GLIP-LIB                                                                                                  */
/*     OpenGL Image Processing LIBrary                                                                           */
/*                                                                                                               */
/*     Author        : R. KERVICHE 			                                                         */
/*     LICENSE       : MIT License                                                                               */
/*     Website       : http://sourceforge.net/projects/glip-lib/                                                 */
/*                                                                                                               */
/*     File          : PipelineManager.hpp                                                                       */
/*     Original Date : May 26th 2014                                                                             */
/*                                                                                                               */
/*     Description   : Qt interface for pipeline interaction.                                                    */
/*                                                                                                               */
/* ************************************************************************************************************* */

#ifndef __GLIPLIB_PIPELINE_MANAGER__
#define __GLIPLIB_PIPELINE_MANAGER__

	// Use QVGL::SubWidget definition :  
	#define __USE_QVGL__

// Includes :
	#include "GLIPLib.hpp"
	#include "ImageItem.hpp"

	#ifdef __USE_QVGL__
		#include "GLSceneWidget.hpp"
	#endif 

namespace QGPM
{
	// Namespaces
	using namespace Glip;
	using namespace Glip::CoreGL;
	using namespace Glip::CorePipeline;
	using namespace Glip::Modules;

	// Classes : 
	class Connection : public QObject
	{
		Q_OBJECT

		private :
			void Connection(void);			// No constructor
			void Connection(const Connection&);	// No copy constructor

		public :
			virtual ~Connection(void);

			virtual bool isValid(void) const = 0;
			virtual const __ReadOnly_HdlTextureFormat& getFormat(void) const = 0;
			virtual HdlTexture& getTexture(void) = 0;
	
		signals :
			void modified(void);
			void statusChanged(bool valid);
			void connectionClosed(void);			
	};

	class ConnectionToImageItem : public Connection
	{
		Q_OBJECT
	
		private : 
			QGIC::ImageItem* imageItem;

		private slots : 
			void imageItemDestroyed(void);

		public : 
			ConnectionToImageItem(QGIC::ImageItem* _imageItem);
			~ConnectionToImageItem(void);

			bool isValid(void) const;
			const __ReadOnly_HdlTextureFormat& getFormat(void) const;
			HdlTexture& getTexture(void);
	};

	class ConnectionToPipelineOutput : public Connection
	{
		Q_OBJECT

		private : 
			PipelineItem*	pipelineItem;
			int		outputIdx;

		private slots : 
			void pipelineItemStatusChanged(void);
			void pipelineItemDestroyed(void);

		public :
			ConnectionToPipleineOutput(PipelineItem* _pipelineItem, int _outputIdx);
			~ConnectionToPipelineOutput(void);

			bool isValid(void) const;
			const __ReadOnly_HdlTextureFormat& getFormat(void) const;
			HdlTexture& getTexture(void);
	};

	class PipelineItem : public QTreeWidgetItem
	{
		private : 
			const QObject*				referrer;
			LayoutLoader				loader;
			std::string				source;
			QString					inputFormatString;
			void*					identifier;
			LayoutLoader::PipelineScriptElements	elements;
			PipelineLayout*				pipelineLayout;
			Pipeline*				pipeline;
			QVector<Connection*>			inputConnectionsList;
			int					cellA,
								cellB,
								computeCount;
			QTreeWidgetItem				inputsNode,
								outputsNode;
			QList<QTreeWidgetItem*>			inputItems,
								outputItems;

			std::string getInputFormatName(int idx);

			void preInterpret(void);
			bool checkConnections(void);
			void interpret(void);
			void compile(void);
			void compute(void);

		private slots : 
			void connectionStatusChanged(bool validity);
			void connectionDestroyed(void);

		public : 
			PipelineItem(const std::string& _source, void* _identifier, const QObject* _referrer, const char* notificationMember);
			~PipelineItem(void);

			void updateSource(const std::string& _source);

			bool isValid(void) const;
			const __ReadOnly__HdlTextureFormat& getOutputFormat(int idx);
			HdlTexture& out(int idx);
	
			void remove(void);

		public slots :
			void makeConnection(QTreeWidgetItem* inputItem, Connection* connection);

		signals : 	
			void statusChanged(void);
			void removed(void);
			void referrerShowUp(void);
			void compilationFailureNotification(void* identifier, Exception compilationError);
	};

	class PipelineManager : public QWidget
	{
		private : 	
			QMap<void*, PipelinItem*>	pipelineItems;
			QList<QGIC::ImageItem*>		imageItems;
			QVBoxLayout			layout;
			QMenuBar			menuBar;
			QTreeWidget			treeWidget;

			void compile(void);
			void compute(void);
			void updatePipelineStatus(void);

		public : 
			PipelineManager(void);
			~PipelineManager(void);

		public slots : 
			void addImageItem(QGIC::ImageItem* imageItem); 
			void compileSource(std::string _source, void* _identifier, const QObject* referrer, const char* notificationMember);
			void removeSource(void* _identifier);	
	};

	#ifdef __USE_QVGL__
	class PipelineManagerSubWidget : public SubWidget
	{
		private : 
			PipelineManager	manager;

		public : 
			PipelineManagerSubWidget(void);
			~PipelineManagerSubWidget(void);

			PipelineManager* getManagerPtr(void);
	};
	#endif
}

#endif
