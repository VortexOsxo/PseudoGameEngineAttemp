#include "game/entity/living_entity.h"

LivingEntity::LivingEntity(Vector2D position, int rayon, float inHealth)
    : Entity(position, rayon), health(inHealth), maxHealth(inHealth)
{
}

void LivingEntity::TakeDamage(float damage)
{
    health -= damage;
}
