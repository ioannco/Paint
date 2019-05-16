#pragma once
#include "../include/WinManager.h"
#include "Person.h"

namespace sf
{
	enum relatives
	{
		parents,
		children
	};

	struct __KOSTYL__ADDITIONAL__  //VERY BAD, BUT STILL WORKING
	{
		Person* p1 = nullptr;
		relatives r1;
	};

	class LinkPersonButton :
		public SpriteWnd
	{
	public:
									 LinkPersonButton (Sprite sprite, Sprite PersonBtnSprite, Sprite iconSprite, Person * person, WindowManager * manager, relatives current);
		virtual	StandardCursor::TYPE GetCursorType   ()								 override;
		virtual bool				 OnClick		 (Event::MouseButtonEvent event) override;
		Sprite	&					 getSprite ();

	protected:
		Sprite						 PersonBtnSprite_, iconSprite_;
		Person *					 person_;
		WindowManager *				 manager_;
		relatives                    currentRelatives_;
	};

	class PersonButton :
		public SpriteWnd
	{
	public:
						   PersonButton		   (Sprite sprite, Sprite addBtnSprite, Sprite iconSprite, Person * person, WindowManager * manager, sf::Font font);
		void			   IntegrateButtons	   ();
		bool			   OnClick			   (Event::MouseButtonEvent event) override;
		bool               OnRelease		   (Event::MouseButtonEvent event) override;
		void		       Draw				   (RenderWindow* wnd)			   override;
						   ~PersonButton	   ();
		Sprite *		   GetSprite		   ();

	protected:
		LinkPersonButton * addParents_, * addChildren_;
		Sprite			   icon_, addBtnSprite_;
		Person *		   person_;
		WindowManager*	   manager_;
		bool			   holding_;
		sf::Vector2f	   msdelta_;
		sf::Font		   font_;
	};

	class AddPersonButton :
		public SpriteWnd
	{
	public:
							   AddPersonButton	(Sprite sprite, WindowManager* manager, Sprite addBtnSprite, Sprite iconSprite, Sprite background);
							   ~AddPersonButton ();
		bool				   OnClick		    (Event::MouseButtonEvent event) override;

	protected:
		Sprite				   addBtnSprite_, iconSprite_, background_;
		std::vector <Person*>  people_;
		WindowManager	*	   manager_;
	};

}

