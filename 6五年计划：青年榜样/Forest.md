# Forest




## GO FETCH
```Python

# You've been caught in a burl trap!
# Send your pet to fetch the health potions!

def goFetch():
    # You can use loops in a handler function.
    while True:
        potion = hero.findNearestItem()
        if potion:
            # Use pet.fetch() to have your pet fetch a potion:
            pet.fetch(potion)
            pass

# When your pet is summoned, it triggers a "spawn" event.
# This tells your pet to run goFetch() at the start of the level
pet.on("spawn", goFetch)


```
此处应该注意文中写的是potion。


```Python



```


## Long Road
```Python
# Move to the right.

# Complete this function:
def onSpawn(event):
    
    # Inside a while-true loop:
    while True:
        # Use hero.findNearestItem()
        item = hero.findNearestItem()
        # If there's an item:
        if item:
            # Use pet.fetch(item) to fetch the item.
            pet.fetch(item)

# Use pet.on() to assign onSpawn to the "spawn" event
pet.on("spawn", onSpawn)

hero.moveXY(76, 35)



```



## Forest Cannon Dancing
```Python
# Your pet should run back and forth on the X marks.
# The hero should cheer the whole time!

# Write the event function onSpawn for the pet.
# This function should make the wolf run back and forth:
# First, run to the right mark, then the left one:
def onSpawn(event):
    while True:
        pet.moveXY(48, 8)
        pet.moveXY(12, 8)


pet.on("spawn",onSpawn)
    
# Cheer up your pet. Don't remove this:
while True:
    hero.say("Run!!!")
    hero.say("Faster!")

```

## REWARD AND RUINATION

```Python
# It seems like the Ogre Chieftain is stealing your gems!
# Use the two artillery cannons to defeat your enemies and gather the gems.

while True:
    enemy = hero.findNearestEnemy()
    if enemy:
        enemyPos = enemy.pos.x + " " + enemy.pos.y
        hero.say("Enemy at " + enemyPos)
        
    # Now that you have sweet revenge, why not have your cake and eat it, too?
    # Find the item's position and say it for your artillery to target.
    item = hero.findNearestItem()
    if item:
        itempos = item.pos.x +" " + item.pos.y
        hero.say("Item at "+ itempos)



```
注意此时需要把两个位置之间加上连接，传递给程序会自动进行分词处理并且说明该如何理解这个内容。


## DEJA BREW

```Python
# You can add strings together, and add numbers into strings.
# Sing along, using string concatenation:
# X potions of health on the wall!
# X potions of health!
# Take Y down, pass it around!
# X-Y potions of health on the wall.

potionsOnTheWall = 10
numToTakeDown = 1
while True:
    hero.say(potionsOnTheWall + " potions of health on the wall!")
    # Sing the next line:
    hero.say(potionsOnTheWall + " potions of health!")
    # Sing the next line:
    hero.say("Take "+ numToTakeDown + "down, pass it around!")
    potionsOnTheWall -= numToTakeDown
    # Sing the last line:
    hero.say(  potionsOnTheWall + " potions of health on the wall.")



```

## BACKWOODS BOMBARIDER

```Python
# The pos property is an object with x and y properties.
# pos.x is a number representing the horizontal position on the map
# pos.y is a number representing the vertical position on the map

while True:
    enemy = hero.findNearestEnemy()
    if enemy:
        x = enemy.pos.x
        # Get the enemy's y position!
        y = enemy.pos.y # ∆ Change this!
        
        # say the x and y position separated by a comma
        hero.say(x + "," + y)
    else:
        hero.say("Cease" + " Fire!")



```
## THE WIZARD'S DOOR


```Python
# Move to Laszlo and get his secret number.
hero.moveXY(30, 13)
las = hero.findNearestFriend().getSecret()

# Add 7 to Laszlo's number to get Erzsebet's number.
# Move to Erzsebet and say her magic number.
erz = las + 7
hero.moveXY(17, 26)
hero.say(erz)

# Divide Erzsebet's number by 4 to get Simonyi's number.
# Go to Simonyi and tell him his number.
simon = erz/4
hero.moveXY(30, 39)
hero.say(simon)
# Multiply Simonyi's number by Laszlo's to get Agata's number.
# Go to Agata and tell her her number.
aga = simon * las
hero.moveXY(43, 26)
hero.say(aga)



```

## THE WIZARD'S HAUNT

```Python
# Move to Zsofia and get the secret number from her.
hero.moveXY(18, 20)
zso = hero.findNearestFriend().getSecret()

# Divide Zsofia's number by 4 to get Mihaly's number.
# Move to Mihaly and say his magic number.
mih = zso / 4
hero.moveXY(30, 15)
hero.say(mih)

# Divide Mihaly's number by 5 to get Beata's number
# Move to Beata and say her magic number.
bea = mih / 5
hero.moveXY(42, 20)
hero.say(bea)


# Subtract Beata's number from Mihaly's to get Sandor's number.
# Move to Sandor and say his magic number.
san = mih - bea 
hero.moveXY(38, 37)
hero.say(san)


```

## THE WIZARD'S PLANE

```Python
# Move to Eszter and get the secret number from her.
hero.moveXY(16, 32)
esz = hero.findNearestFriend().getSecret()

# Multiply by 3 and subtract 2 to get Tamas's number.
# Remember to use parentheses to do calculations in the right order.
# Move to Tamas and say his magic number.
tam = (esz * 3) - 2
hero.moveXY(24, 28)
hero.say(tam)

# Subtract 1 and multiply by 4 to get Zsofi's number.
# Move to Zsofi and say her magic number.
zso = (tam - 1) * 4
hero.moveXY(32, 24)
hero.say(zso)
# Add Tamas's and Zsofi's numbers, then divide by 2 to get Istvan's number.
# Move to Istvan and say his magic number.
ist = (tam + zso) / 2
hero.moveXY(40, 20)
hero.say(ist)
# Add Tamas's and Zsofi's numbers. Subtract Istvan's number from Zsofi's. Multiply the two results to get Csilla's number.
# Move to Csilla and say her magic number.
csi = (tam + zso) * (zso - ist)
hero.moveXY(48, 16)
hero.say(csi)



```

## COINRUMBERS

```Python
# Follow the trail of coins to the red X at the exit.

while True:
    # This finds the nearest item.
    item = hero.findNearestItem()
    if item:
        # This stores the item's pos, or position in a variable.
        itemPosition = item.pos
        # Put the X and Y coordinates of the item into variables.
        itemX = itemPosition.x
        itemY = itemPosition.y
        # Now, use moveXY to move to itemX and itemY:
        hero.moveXY(itemX, itemY)



```

## WHITE RABIT

```Python
# Follow the lightstone to navigate the traps.

while True:
    item = hero.findNearestItem()
    if item:
        # Store the item's position in a new variable using item.pos:
        pos = item.pos
        # Store the X and Y coordinates using pos.x and pos.y:
        x = pos.x
        y = pos.y
        # Move to the coordinates using moveXY() and the X and Y variables:
        hero.moveXY(x, y)
        pass


```

## CHAMELEONS

```Python

# Ogres are disguised as coins or gems!

while True:
    enemy = hero.findNearestEnemy()
    # If you see an enemy - attack it:
    if enemy:
        hero.attack(enemy)
    item = hero.findNearestItem()
    # If you see a coin or a gem - move to it's X and Y position:
    if item:
        hero.moveXY(item.pos.x,  item.pos.y)


```

## BLIND DISTANCE

```Python
# Tell the wizard the distance to the coming ogres.

# This function finds the nearest enemy and returns the distance to it.
# If there is no enemy, the function returns 0.
def nearestEnemyDistance():
    enemy = hero.findNearestEnemy()
    result = 0
    if enemy:
        result = hero.distanceTo(enemy)
    return result

while True:
    # Call nearestEnemyDistance() and
    # save the result in the variable enemyDistance.
    enemyDistance = nearestEnemyDistance()
    # If the enemyDistance is greater than 0: 
    if enemyDistance > 0:
        # Say the value of enemyDistance variable.
        hero.say(enemyDistance)

```

## HIT AND FREEZE

```Python



```

## BURLBOLE GROVE

```Python
# Don't attack the burls!
# Functions can return a value.
# When a function is called, it will be equal to the value the function returns.

def shouldAttack(target):
	# return False if no target
    if not target:
        return False
	# return False if target.type == "burl"
    if target.type == "burl":
        return False
    # Otherwise, return True
    return True

while True:
    enemy = hero.findNearestEnemy()
    # Here we use shouldAttack() to decide if we should attack!
    # heroShouldAttack will be assigned the same value that shouldAttack() returns!
    heroShouldAttack = shouldAttack(enemy)
    if heroShouldAttack:
    	hero.attack(enemy)



```
## COIN HUNTER

```Python

# To make the training more interesting Senick poisoned you.
# While you aren't moving the poison is harmless.

# This function should check if a coin is closer than 20m.
def isCoinClose(coin):
    # Find the distance to the coin.
    distance = hero.distanceTo(coin)
    # If the distance is less than 20: 
    if distance < 20:
        # Return True
        return True
    # Else:
    else:
        # Return False
        return False
    pass

while True:
    item = hero.findNearestItem()
    if item:
        # If isCoinClose(item) returns true:
        if isCoinClose(item):
            hero.moveXY(item.pos.x, item.pos.y)


```
## SALTED EARTH

```Python

# Ogres are attacking a nearby settlement!
# Be careful, though, for the ogres have sown the ground with poison.
# Gather coins and defeat the ogres, but avoid the burls and poison!

while True:
    enemy = hero.findNearestEnemy()
    if enemy.type == "munchkin" or enemy.type == "thrower":
        hero.attack(enemy)
    item = hero.findNearestItem()
    # Check the item type to make sure the hero doesn't pick up poison!
    # Look for types: 'gem' and 'coin'
    if item.type != "poison":
        hero.moveXY(item.pos.x, item.pos.y)


```
需要对具体内容有所了解，不能仅仅获得就可以。获得就是走到那个位置去就可以。


## METAL DETECTOR

```Python

# The artillery uses coins as a target.
# You'll be the rangefinder for the artillery.

# Write the function.
def coinDistance():
    # Find the nearest coin,
    item = hero.findNearestItem()
    
    # If there is a coin, return the distance to it.
    if item:
        distance = hero.distanceTo(item)
        return distance
    # Else, return 0 (zero).
    else:
        return 0
    

while True:
    distance = coinDistance()
    if distance > 0:
        # Say the distance.
        hero.say(distance)
        pass


```
distance和item都得是进行确认过之后才能使用的变量，那么distance也要在item使用之后得到这个变量，毕竟得先if确认，确认过后可以得到这个变量内容。

```Python



```


```Python



```


```Python



```


```Python



```


```Python



```


```Python



```


```Python



```


```Python



```


```Python



```


```Python



```


```Python



```


```Python



```


```Python



```


```Python



```


```Python



```


```Python



```


```Python



```


```Python



```


```Python



```


```Python



```


```Python



```


```Python



```


```Python



```


```Python



```


```Python



```


```Python



```


```Python



```


```Python



```


```Python



```


```Python



```


```Python



```


```Python



```


```Python



```


```Python



```


```Python



```


```Python



```


```Python



```


```Python



```


```Python



```


```Python



```


```Python



```


```Python



```


```Python



```

