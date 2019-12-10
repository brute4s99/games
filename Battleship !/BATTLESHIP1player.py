from random import randint
#CREATE THE OCEAN FULL OF "O"s
""" IMPORTANT VARs :-
        dim -> No. of Slots per ROW , and also No. of ROWs
        ship_length
        orientation
        ship_coordinates
        guesses
        guess
"""
comments=["Show'em who's the boss ! \n;)","Storm the Seas !","Sweet !\n","Lucky Guess ...","Go get'em !"]
print "BATTLESHIP !!!"

board =[]
dim=int(raw_input("Size of Board ? : "))
for j in range(dim):
    board.append(list("O" * dim))

    
#Land the ship somewhere
print "SETTING UP A SHIP....\nStand By....\nDONE !!!!"
ship_length=randint(1,dim)
orientation=randint(0,1)    # 0= HORIZONTAL SHIP (row -> const) AND  1= VERTICAL SHIP (column -> const)
ship_coordinates=[]
if orientation == 0 :
    ship_startrow=randint(0,dim-1)
    ship_startcol=randint(0,dim-ship_length)
    for x in range(0,ship_length):
        ship_coordinates.append(list(str(ship_startrow)+str(ship_startcol+x)))
else:
    ship_startcol=randint(0,dim-1)
    ship_startrow=randint(0,dim-ship_length)
    for x in range(ship_length):
        ship_coordinates.append(list(str(ship_startrow+x)+str(ship_startcol)))
for i in range(0,dim):
    print " ".join(board[i])
#Let The Games Begin ...
guesses=10
hit_count=0
print "Input Form -> ROW COL\n COORDINATES START FROM 1"
while guesses>0 and hit_count < ship_length:
    guesses-=1
    guess=raw_input("Enter Coordinates to FIRE CANNON : ")
    if guess=="rebirth":                          # CHEAT CODE FOR +3 GUESSES
        print "Cheat Activated !"
        guesses+=4
        print "Guesses Left : "+str(guesses)
    elif guess=="finalhint":                       # CHEAT CODE FOR LOCATION REVELATION  
        if orientation==0:
            print "CHEAT ACTIVATED !!!\nIt's in Row "+str(ship_startrow+1)
        else:
            print "CHEAT ACTIVATED !!!\nIt's in Column "+str(ship_startcol+1)
        guesses+=1
    elif guess=="giveahint":                       # CHEAT CODE FOR ORIENTATION REVELATION  
        if orientation==0:
            print "CHEAT ACTIVATED !!!\nIt's Horizontally Placed."
        else:
            print "CHEAT ACTIVATED !!!\nIt's Vertically Placed."
        guesses+=1
    else:
        x=int(guess[0])-1
        y=int(guess[2])-1
        if x not in range(0,dim) or y not in range(0,dim):
            print "Guesses Left : "+str(guesses)
        elif list(str(x)+str(y)) in ship_coordinates:
            print "\nTHAT'S A HIT !!!"
            h=randint(0,5)
            print comments[h]                        # A nice comment
            guesses+=1
            hit_count+=1
            board[x][y]='X'
            for p in range(0,dim):
                print " ".join(board[p])
            print "Guesses Left : "+str(guesses)
        elif board[x][y]=='X':
            print "You have fired the cannon there already !"
            guesses+=1
        else:
            print "**blop**\n"
            board[x][y]='X'
            for p in range(0,dim):
                print " ".join(board[p])
            print "Guesses Left : "+str(guesses)
if ship_length==hit_count:
    print "You sunk my BATTLESHIP !\n Congratulations !!!"
else:
    x=raw_input("Want some more chances ?\n(y/n)")
    if x=='y' or x=='Y':
        print "It's good to have some beautiful choices in life, but this game is over for you.\n Xp\n"
    elif x=='n' or x=='N':
        print "That's my boy !\n"
    else:
        print "...\n...\nAnyways..."
print "GAME OVER"
        
