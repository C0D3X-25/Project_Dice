# Dice_Reroll

## Game References
This game is set in a Medieval Fantasy Universe and is inspired by:
- **Slice and Dice** (Most of the ideas are based on it)
- **The Rules of DnD 5e** (For stats, capacities, and dice mechanics)
- **Slay the Spire** (For the game layout, events, and some combat mechanics)
- **Battle Brotters** (For some combat mechanics and character creation/management)

## Game Loop
This dice game revolves around managing a group of characters (group size is not fixed but likely ranges from 1 to 5-6) in turn-based combat against a group of enemies.  
The objective is to defeat all enemies before the player's group is eliminated and progress to the next zone.

### Game Start
The game starts with a group of 2 completely random characters, each with their own stats, items, and dice of capacities.  
The player can recruit up to 2 new characters from 5 proposed options and has 1 reroll to change the proposed characters.

### Combat
Combat is turn-based, where each character can attack, provide armor, heal, or apply status effects using their capacities.  
The combat is divided into three phases:

1. **Starting Phase** (only at the start of combat):
   - The enemy group composition is generated based on the zone and other modifiers.
   - Starting statuses and effects are applied to all characters in combat.
   - Enemy characters select a capacity to use when the player's turn ends.

2. **Player Phase**:
   - The player can generally see the next capacity the enemies will use.
   - Status effects are applied to all player characters.
   - Dice for each player's capacities are rolled.
   - The player can assign capacities to characters and/or reroll the capacity dice.
   - Some capacities are used immediately when assigned to a character, even if the dice are rerolled.
   - Other capacities are used at the end of the turn, after all capacity dice are assigned to characters.
   - The order of capacity usage for player characters is determined by their speed.
   - Characters with the same speed act from top to bottom.

3. **Enemy Phase**:
   - Status effects are applied to all enemy characters.
   - Enemy characters use the capacities assigned at the beginning of the turn.
   - The order of capacity usage for enemy characters is determined by their speed.
   - Characters with the same speed act from top to bottom.
   - Enemy characters select a capacity to use when the player's turn ends.

### Events
The game is divided into zones, each with a specific theme and unique events.

## Characters
Every character (player and enemy) has the following stats:
- **Life**: The amount of life the character has. When it reaches 0, the character dies permanently (almost).
- **Armor**: The most common way to protect a character; it absorbs most damage.
- **Strength**: Focuses on capacities that deal high damage in a single hit to one or nearby enemies. Increases the ability to equip heavy items.
- **Dexterity**: Focuses on capacities that deal multiple hits to a single enemy. Increases the character's speed.
- **Constitution**: Focuses on capacities that use life for their effects. Increases the character's life.
- **Intelligence**: Focuses on damaging capacities that affect a large number of enemies, typically magic. Increases the ability to equip magical items.
- **Wisdom**: Focuses on supportive capacities. Enhances the effectiveness of status effects on the character.

Each character has a dice containing 10 capacities, which can be changed, upgraded, or modified.
Characters also have feats, which can be beneficial or detrimental.

### Stats
Stats are the core of the game and are used to determine the effectiveness of capacities and the eligibility to equip items.  
They range from -10 to 20, with -10 being the worst and 20 being the best. The average is around 0.  
Stats cannot go below -10, and values above 20 are only possible with items.

### Feats
Feats are abilities that provide bonuses or effects to characters in combat.  
They are not directly related to the dice of capacities but can modify them.  
It is rare to remove feats, but it is more common to add new ones.

Examples of feats:
- **Strong**: The character has increased strength.
- **Cursed**: The character's dice of capacities cannot be rerolled.
- **Hard Skin**: The character starts combat with armor.

### Dice of Capacities
The dice of capacities contain 10 faces, each representing a capacity.  
Items are the primary way to modify the dice of capacities, but feats can also alter them.  
In general, the capacities are divided into 3 zones of the dice:
- **1-3**: Offensive
- **4-6**: Defensive
- **7-9**: Support
- **10**: Special

### Capacities
Capacities allow characters to deal damage, provide armor, heal, or apply status effects (e.g., burning, poison). These actions are influenced by the stats and items of the entity using them.  

During the player's turn:
- All capacity dice are rolled, and the player can assign capacities to any entity, regardless of who owns the dice.
- The effectiveness of a capacity depends on the stats of the entity using it, so the player must decide whether to accept reduced effects or reroll the dice.
- Dice not assigned to an entity will be rerolled, but rerolls are limited to 2 times per turn by default (modifiable by items or capacities).

Capacities are generally used at the end of the turn, after all dice are assigned.  
Some capacities are used immediately when assigned to an entity, even if the dice are rerolled.  
Certain capacities are cursed and can only be used by the entity that owns the dice and/or cannot be rerolled.  
Capacities have rarity levels, which determine their power.

### Status Effects
Status effects are temporary effects that can be applied to characters.  
They can be beneficial or detrimental and are removed at the end of combat or by certain capacities.  
Each status effect can be stacked or not, and it can be modified by items or capacities.  
Their effects are applied at the beginning of the turn, before the player/enemy phase.  
A stack is removed at the beginning of the turn after being resolved.

Examples of status effects:
- **Burning**: Deals damage to armor and life; can be stacked.
- **Poison**: Deals damage to life; can be stacked.
- **Corrosion**: Deals damage to armor first and can apply negative armor if none is left.

## Upgrades
### Leveling Characters
Characters can upgrade their stats and passives using XP. XP is not shared across the group, so characters can have different levels.  
Capacities can also be upgraded, but the upgrade applies to the face of the dice or a certain type of capacity.

### Items
Characters can modify their stats with items. Items are not restricted to specific characters but may be limited by the stats of a character.  
Most items also affect the capacity dice by adding capacities to certain spots.  
Items have rarity levels, which determine their power.

## Enemies
To prevent players from stacking the same stats on their characters, enemies have resistances to certain stats, reducing the effectiveness of capacities used by player characters.

### Loot
Enemies can drop items.  
Events can also provide items.

## Where is the Fun?
The fun lies in managing a group of characters, their stats, and their items.  
Players can recruit new characters, upgrade them, and manage their capacities.  
Rolling dice and taking risks with rerolls adds an element of chance and strategy.
