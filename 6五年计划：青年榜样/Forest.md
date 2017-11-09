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

