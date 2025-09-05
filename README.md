# Dice_Reroll

## Game References
This game is set in a Medieval Fantasy Universe and is inspired by:
- **Slice and Dice** (Most of the ideas are based on it)
- **The Rules of DnD 5e** (For attributes, capacities, and dice mechanics)
- **Darkest Dungeon** (For the character management, some combat mechanics and items balance)
- **Slay the Spire** (For the game layout, events and some combat mechanics)
- **Battle Brothers** (For some combat mechanics, feats balance and character creation/management)

## Difficulties
The game is designed to be challenging, with a high level of difficulty.
Death is permanent, and the player must manage their group of characters carefully to survive.

## Game Loop
This dice game revolves around managing a group of characters (group size is not fixed but likely ranges from 1 to 5-6) in turn-based combat against a group of enemies.  
The objective is to defeat all enemies before the player's group is eliminated and progress to the next zone.

### Game Start
The game starts with a group of 2 completely random characters, each with their own attributes, items, and dice of capacities.  
The player can recruit up to 2 new characters from 5 proposed options and has 1 reroll to change the proposed characters.

### Combat
Combat is turn-based, where each character can attack, provide armour, heal, or apply status effects using their capacities.  
The combat is divided into three phases:

1. **Starting Phase** (only at the start of combat):
   - The enemy group composition is generated based on the zone and other modifiers.
   - Starting passives are applied to all characters in combat.
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
Every character (player and enemy) has the following attributes:
- **Life**: The amount of life the character has. When it reaches 0, the character dies permanently (almost).
- **Armour**: The most common way to protect a character; it absorbs most damage. Armour is remove when the character is starting is turn.
- **Strength**: Focuses on capacities that deal high damage in a single hit to one or nearby enemies. Increases the ability to equip heavy items.
- **Dexterity**: Focuses on capacities that deal multiple hits to a single enemy. Increases the character's speed.
- **Constitution**: Focuses on capacities that use life for their effects. Increases the character's life.
- **Intelligence**: Focuses on damaging capacities that affect a large number of enemies, typically magic. Increases the ability to equip magical items.
- **Wisdom**: Focuses on supportive capacities. Enhances the effectiveness of status effects on the character.
- **Charisma**: Focuses on capacities that affect the character's allies. Increases the ability to equip items that provide bonuses to allies.

Each character has a dice containing 10 capacities, which can be changed, upgraded, or modified.
Characters also have feats, which can be beneficial or detrimental.

### Attributes
Attributes are the core of the game and are used to determine the effectiveness of capacities and the eligibility to equip items.  
They range from -10 to 20, with -10 being the worst and 20 being the best. The average is around 2.  
Attributes cannot go below -10, and values above 20 are only possible with items.

### Feats
Feats are passives that provide bonuses or effects to characters in combat.  
They are not directly related to the dice of capacities but can modify them.  
It is rare to remove feats, but it is more common to add new ones.

Examples of feats:
- **Strong**: The character has increased strength.
- **Cursed**: The character's dice of capacities cannot be rerolled.
- **Hard Skin**: The character starts combat with armour.
- **Lucky**: The character has a chance to reroll a capacity dice when it's "do nothing"".

### Dice of Capacities
The dice of capacities contain 10 faces, each representing a capacity.  
Items are the primary way to modify the dice of capacities, but feats can also alter them.  
In general, the capacities are divided into 3 zones of the dice:
- **1-3**: Offensive
- **4-6**: Defensive
- **7-9**: Support
- **10**: Special

### Capacities
Capacities allow characters to deal damage, provide armour, heal, or apply status effects (e.g., burning, poison). These actions are influenced by the attributes and items of the character using them.  

During the player's turn:
- All capacity dice are rolled, and the player can assign capacities to any character, regardless of who owns the dice.
- The effectiveness of a capacity depends on the attributes of the character using it, so the player must decide whether to accept reduced effects or reroll the dice.
- Dice not assigned to an character will be rerolled, but rerolls are limited to 2 times per turn by default (modifiable by items or capacities).

Capacities are generally used at the end of the turn, after all dice are assigned.  
Some capacities are used immediately when assigned to an character, even if the dice are rerolled.  
Certain capacities are cursed and can only be used by the character that owns the dice and/or cannot be rerolled.  
Capacities have rarity levels, which determine their power.

### Status Effects
Status effects are temporary effects that can be applied to characters.  
They can be beneficial or detrimental and are removed at the end of combat or by certain capacities.  
Each status effect can be stacked or not, and it can be modified by items or capacities.  
Their effects are applied at the beginning of the turn, before the player/enemy phase.  
A stack is removed at the beginning of the turn after being resolved.

Examples of status effects:
- **Burning**: Deals damage to armour and life; can be stacked.
- **Poison**: Deals damage to life; can be stacked.
- **Corrosion**: Deals damage to armour.

### Passives
Passives are effects that modify the character's attributes, capacities, or other aspects of the game.
They are active under certain conditions, such as having a certain pourcent of life, 
having a certain status effect of using a specific type of capacity.

## Upgrades
### Rarity
Rarity is a measure of the power of items and capacities.
- **Common**: Basic items and capacities, no special effects.
- **Uncommon**: Slightly more powerful items and capacities, may have minor effects.
- **Rare**: Powerful items and capacities, often require to have certain attributes/level to use.
- **Mythic**: Unique items and capacities with significant effects.
- **Legendary**: Extremely powerful items and capacities, often game-changing and unique.
- **Relic**: The most powerful items and capacities, often with unique mechanics or effects that can alter the course of the game. Cursed items are often Relics.

### Leveling Characters
Characters can upgrade their attributes and passives using XP. XP is not shared across the group, so characters can have different levels.  
Capacities can also be upgraded, but the upgrade applies to the face of the dice or a certain type of capacity.

### Items
Characters can modify their attributes with items. Items are not restricted to specific characters but may be limited by the attributes or level of a character.  
Most items also affect the capacity dice by adding capacities to certain side, one or more.  
Items have rarity levels, which determine their power and chance to be found.

Items can be equipped in specific equipment slots:
- **Helmet**: Provides additional armour and defensive capacities.
- **Body Armour**: Provides additional armour and defensive capacities.
- **Shoulder Armour**: Provides additional armour and defensive capacities.
- **Arm Guards**: Provides additional armour and defensive capacities.
- **Gloves**: Provides additional armour and may have special effects like dodge AOE attack.
- **Leg Armour**: Provides additional armour and may have special effects like dodge AOE attack.
- **Boots**: Provides additional armour and may have special effects like dodge AOE attack.
- **Ring Right**: Provides various bonuses, typically to attributes or capacities.
- **Ring Left**: Provides various bonuses, typically to attributes or capacities.
- **Amulet**: Provides various bonuses, typically to attributes or capacities.
- **One-Handed Right**: Provides offencive capacities.
- **One-Handed Left**: Provides offencive capacities, a part of the right-handed items can be used in the left hand (with malus).
- **Two-Handed**: Provides offencive capacities.

***Equipment Slot doesn't mean that the item is always providing the bonuses mentioned above.***

***Example of items can be found in doc/Item_Idea.md***

## Enemies
To prevent players from stacking the same attributes on all their characters, enemies have resistances to certain attributes, reducing the effectiveness of capacities used by player characters.

### Loot
Enemies can drop items.  
Events can also provide items.

## Where is the Fun?
The fun lies in managing a group of characters, their attributes, and their items.
Players can recruit new characters, upgrade them, and manage their capacities.  
Rolling dice and taking risks with rerolls adds an element of chance and strategy.
