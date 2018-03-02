#pragma once

#include "ResourceHolder.h"

namespace sf
{
	class Texture;
}

namespace Textures
{
	enum ID
	{
		PlayerRed,
		PlayerBlue,
		Map
	};
}

template <typename Resource, typename Identifier>
class ResourceHolder;

typedef ResourceHolder<sf::Texture, Textures::ID> TextureHolder;