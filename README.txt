
In the game world, there are several kingdoms. Each kingdom has a number of its own troops in the army. Kingdoms can be independent or vassal, and each kingdom belongs to a culture, which cannot be changed over time.
If kingdom A is a vassal, then it is subordinate to another kingdom B. Kingdom B is called the suzerain of kingdom A, and kingdom A is called the vassal of kingdom B. Each vassal kingdom, depending on its culture, will provide a certain number of troops to the suzerain kingdom to which it belongs. Regardless of culture, a kingdom cannot provide more than half of its total troops (which includes the troops it receives from its own vassals, if any).
In the game world, there are 3 important cultures:
● Byzantine culture - vassals from this culture will provide a fixed number of troops to the suzerain kingdom they belong to.
● Frankish culture - vassals from this culture will provide a percentage of the total number of troops they have to the suzerain kingdom they belong to.
● Anglo-Saxon culture - vassals from this culture will provide a percentage of the total number of troops they have to the suzerain kingdom they belong to, but not less than a fixed value.
The troops given to the suzerain kingdom will no longer belong to the vassal kingdom. For example, the Kingdom of Crete, a Byzantine culture kingdom, is vassalized by the Byzantine Empire. The Kingdom of Crete has 2500 troops and due to its culture will offer 1000 troops to the Byzantine Empire, thus remaining with 1500 troops. The Byzantine Empire had 52000 troops and will receive the 1000 troops for a total of 53000 troops.
Knowing the description of all the kingdoms at the beginning of the game, as well as how they are vassals to each other, display, in the order of entry, the total number of troops of each kingdom.

Input:
On the first line N and M, the number of kingdoms in the game and the number of vassal relationships.
Follow N lines, each describing a kingdom:
KINGDOM_NAME OWN_TROOPS CULTURE SPECIFIC_PARAMETERS
where KINGDOM_NAME represents the name of the kingdom, without spaces, CULTURE represents one of {BYZANTINE / FRANK / ANGLO-SAXON}, and SPECIFIC_PARAMETERS depend on the culture:
● For BYZANTINE culture, a natural number, the fixed number of troops the kingdom will offer when it is a vassal.
● For FRANK culture, a natural number less than or equal to 50, the percentage of troops the kingdom will offer when it is a vassal.
● For ANGLO-SAXON culture, 2 integers, the first one less than or equal to 50, the percentage of troops the kingdom will offer when it is a vassal, and the second one the minimum number of troops.
Follow M lines, each describing a vassal relationship
VASAL_KINGDOM_NAME SUZERAIN_KINGDOM_NAME

Output:
N lines, on each line, in the order of reading, the name of the kingdom and the total number of troops it has.

Observations
It is guaranteed that if a kingdom appears as a vassal, it will not appear again as a vassal.
It is guaranteed that if a kingdom appears as a vassal, it will not appear later as a suzerain.
Kingdoms that do not appear as vassals are independent.
If a vassal kingdom from an ANGLO-SAXON culture has 2000 troops and parameters "10 1200", it will offer only 1000 troops. 10% of 2000 is 200, but it must offer at least 1200. 
At the same time, it cannot offer more than half, which is the strongest condition.
For cultures {FRANK, ANGLO-SAXON} the number of troops given to the suzerain kingdom is calculated as the integer part of (percentage * number_of_troops) / 100.
The total number of troops is also considered with the troops received from vassals.
