#include <iostream>
#include <string>

#include <cctype>

#include <windows.h>

#include <TGUI/TGUI.hpp>

#include "WTFlaze.h"

void pressKey( char key, bool shift = false )
{
    if( shift ) keybd_event( VK_LSHIFT, 0x45, KEYEVENTF_EXTENDEDKEY | 0, 0 );
    keybd_event( key, 0x45, KEYEVENTF_EXTENDEDKEY | 0, 0 );
    keybd_event( key, 0x45, KEYEVENTF_EXTENDEDKEY | KEYEVENTF_KEYUP, 0 );
    if( shift ) keybd_event( VK_LSHIFT, 0x45, KEYEVENTF_EXTENDEDKEY | KEYEVENTF_KEYUP, 0 );
}

int main()
{
    sf::ContextSettings context;
    context.antialiasingLevel = 16;
    sf::RenderWindow win{ sf::VideoMode{ 400, 400 }, "spam bot", sf::Style::Titlebar | sf::Style::Close, context };
    win.setIcon( icon.width,  icon.height,  icon.pixel_data );
    tgui::Gui gui{ win };

    bool run{ false };
    sf::Time cooldown_set{ sf::milliseconds( 100 ) };
    sf::Time cooldown{ sf::milliseconds( 0 ) };
    std::string spam;

    try
    {
        tgui::Theme theme( "media/BabyBlue.txt" );
        tgui::Theme::setDefault( &theme );

        auto spam_text = tgui::Label::create();
        spam_text->setTextSize( 15 );
        spam_text->setPosition( 50, 80 );
        spam_text->setText( "spam text" );
        gui.add( spam_text, "spam text" );

        auto spam_box = tgui::EditBox::create();
        spam_box->setSize( 300, 30 );
        spam_box->setPosition( 50, 100 );
        spam_box->setText( "place spam text here" );
        gui.add( spam_box, "spam box" );

        auto cooldown_text = tgui::Label::create();
        cooldown_text->setTextSize( 15 );
        cooldown_text->setPosition( 50, 155 );
        cooldown_text->setText( "cooldown time ( ms )" );
        gui.add( cooldown_text, "cooldownt text" );

        auto cooldown_box = tgui::EditBox::create();
        cooldown_box->setSize( 150, 30 );
        cooldown_box->setPosition( 50,175 );
        cooldown_box->setText( "100" );
        gui.add( cooldown_box, "cooldown box" );

        auto cooldown_btn = tgui::Button::create();
        cooldown_btn->setSize( 30, 30 );
        cooldown_btn->setPosition( 210, 175 );
        cooldown_btn->setText( "set" );
        cooldown_btn->connect( "pressed", [&cooldown_set, &gui, &cooldown]{
                                try
                                {
                                    std::string temp = gui.get<tgui::EditBox>( "cooldown box" )->getText().toAnsiString();
                                    int num = std::stoul( temp );
                                    cooldown_set = sf::milliseconds( num );
                                }
                                catch( const std::invalid_argument& e )
                                {
                                    std::cerr << "the cooldown is not a number, please insert number\n";
                                }
                                catch( const std::out_of_range& e )
                                {
                                    std::cerr << "the milliseconds you put in is too big\n";
                                }
                              } );
        gui.add( cooldown_btn, "cooldown btn" );

        auto start_btn = tgui::Button::create();
        start_btn->setSize( 50, 50 );
        start_btn->setPosition( 100, 250 );
        start_btn->setText( "start" );
        start_btn->connect( "pressed", [&spam, &run, &gui, &cooldown]{
                            run = true;
                            spam = gui.get<tgui::EditBox>( "spam box" )->getText().toAnsiString();
                            cooldown = sf::milliseconds( 0 );
                         } );
        gui.add( start_btn, "start btn" );

        auto stop_btn = tgui::Button::create();
        stop_btn->setSize( 50, 50 );
        stop_btn->setPosition( 250, 250 );
        stop_btn->setText( "stop" );
        stop_btn->connect( "pressed", [&spam, &run, &gui]{
                            run = false;
                            spam = gui.get<tgui::EditBox>( "spam box" )->getText().toAnsiString();
                         } );
        gui.add( stop_btn, "stop btn" );
    }
    catch( const tgui::Exception& e)
    {
        std::cerr << "err " << e.what() << '\n';
    }

    sf::Clock clock;

    sf::RectangleShape indicator{ sf::Vector2f{30, 30 } };
    indicator.setPosition( 110, 300 );

    while( win.isOpen() )
    {
        sf::Event e;
        while( win.pollEvent( e ) )
        {
            if( e.type == sf::Event::Closed ) win.close();

            gui.handleEvent( e );
        }
        cooldown -= clock.restart();

        if( ( run ) && ( cooldown <= sf::milliseconds( 0 ) ) )
        {
            for( auto& c : spam )
            {
                switch( c )
                {
                case '`':
                    pressKey( VK_OEM_3 );
                    break;
                case '~':
                    pressKey( VK_OEM_3, true );
                    break;
                case '!':
                    pressKey( 0x31, true );
                    break;
                case '@':
                    pressKey( 0x32, true );
                    break;
                case '#':
                    pressKey( 0x33, true );
                    break;
                case '$':
                    pressKey( 0x34, true );
                    break;
                case '%':
                    pressKey( 0x35, true );
                    break;
                case '^':
                    pressKey( 0x36, true );
                    break;
                case '&':
                    pressKey( 0x37, true );
                    break;
                case '*':
                    pressKey( 0x38, true );
                    break;
                case '(':
                    pressKey( 0x39, true );
                    break;
                case ')':
                    pressKey( 0x30, true );
                    break;
                case '0':
                    pressKey( 0x30 );
                    break;
                case '1':
                    pressKey( 0x31 );
                    break;
                case '2':
                    pressKey( 0x32 );
                    break;
                case '3':
                    pressKey( 0x33 );
                    break;
                case '4':
                    pressKey( 0x34 );
                    break;
                case '5':
                    pressKey( 0x35 );
                    break;
                case '6':
                    pressKey( 0x36 );
                    break;
                case '7':
                    pressKey( 0x37 );
                    break;
                case '8':
                    pressKey( 0x38 );
                    break;
                case '9':
                    pressKey( 0x39 );
                    break;
                case '-':
                    pressKey( VK_OEM_MINUS );
                    break;
                case '_':
                    pressKey( VK_OEM_MINUS, true );
                    break;
                case '+':
                    pressKey( VK_OEM_PLUS );
                    break;
                case '=':
                    pressKey( VK_OEM_PLUS, true );
                    break;
                case '[':
                    pressKey( VK_OEM_4 );
                    break;
                case '{':
                    pressKey( VK_OEM_4, true );
                    break;
                case ']':
                    pressKey( VK_OEM_6 );
                    break;
                case '}':
                    pressKey( VK_OEM_6, true );
                    break;
                case '\\':
                    pressKey( VK_OEM_5 );
                    break;
                case '|':
                    pressKey( VK_OEM_5, true );
                    break;
                case ';':
                    pressKey( VK_OEM_1 );
                    break;
                case ':':
                    pressKey( VK_OEM_1, true );
                    break;
                case '\'':
                    pressKey( VK_OEM_7 );
                    break;
                case '"':
                    pressKey( VK_OEM_7, true );
                    break;
                case ',':
                    pressKey( VK_OEM_COMMA );
                    break;
                case '<':
                    pressKey( VK_OEM_COMMA, true );
                    break;
                case '.':
                    pressKey( VK_OEM_PERIOD );
                    break;
                case '>':
                    pressKey( VK_OEM_PERIOD, true );
                    break;
                case '/':
                    pressKey( VK_OEM_2 );
                    break;
                case '?':
                    pressKey( VK_OEM_2, true );
                    break;
                case ' ':
                    pressKey( VK_SPACE );
                    break;
                default:
                    if( isupper( c ) ) pressKey( c, true );
                    else
                    {
                        char temp = toupper( c );
                        pressKey( temp );
                    }
                }
                cooldown = cooldown_set;
            }
            keybd_event( VK_RETURN, 0x45, KEYEVENTF_EXTENDEDKEY | 0, 0 );
            keybd_event( VK_RETURN, 0x45, KEYEVENTF_EXTENDEDKEY | KEYEVENTF_KEYUP, 0 );
            //cooldown = cooldown_set;
        }

        if( run ) indicator.setFillColor( sf::Color::Blue );
        else indicator.setFillColor( sf::Color::Red );

        win.clear();
        win.draw( indicator );
        gui.draw();
        win.display();
    }
}
