#include "View.h"

void View::SetPlayerView(sf::Vector2f position) 
{ 
	sf::Vector2f temporary = position;

	if (position.x < 320)
		temporary.x = 320;//������� �� ���� ����� �������
	if (position.y < 240)
		temporary.y = 240;//������� �������
	if (position.y > 554)
		temporary.y = 554;//������ �������	

	m_view.setCenter(temporary); //������ �� �������, ��������� ��� ����������. 

}