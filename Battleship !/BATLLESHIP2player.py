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
comments=["Show'em who's the boss ! \n;)","Storm the Seas !","AAg lagaa de , AAg lagaa de ! \n:p","Sweet !\n","Lucky Guess ...","Go get'em !"]
print "BATTLESHIP !!!"
dim=int(raw_input("Board Size : "))
p1_board =[]
p2_board =[]
for j in range(dim):
    p1_board.append(list("O" * dim))
    p2_board.append(list("O" * dim))

    
#Land the ships somewhere

print "Input Form -> ROW COL\n COORDINATES START FROM 1"
print "SETTING UP A SHIP for Player 1....\nStand By..."
for j in range(dim):
    print " ".join(p1_board[j])
p1_ship_length=-9
c=0
while (p1_ship_length<1) or p1_ship_length>dim:
    if c==0:
        p1_ship_length=int(raw_input("Ship Length :"))
    else:
        p1_ship_length=int(raw_input("Ship Length [1-"+str(dim)+"] :"))
p1_orientation=int(raw_input("0->Horizontal\n1->Vertical\nOrientation : "))    # 0= HORIZONTAL SHIP (row -> const) AND  1= VERTICAL SHIP (column -> const)
p1_ship_coordinates=[]
p1_ship_startrow=90
p1_ship_startcol=90
    
if p1_orientation == 0 :
    while (p1_ship_startrow not in range(0,dim)) or (p1_ship_startcol not in range(0,dim-p1_ship_length+1)):
        yo=raw_input("First Coordinates : ")
        p1_ship_startrow=int(yo[0])-1
        p1_ship_startcol=int(yo[2])-1
        if (p1_ship_startrow not in range(0,dim)):
            print "Better Row Required"
        if (p1_ship_startcol not in range(0,dim-p1_ship_length+1)):
            print "Better Column Required"
    print "Creating the Ship...."
    for x in range(0,p1_ship_length):
        p1_ship_coordinates.append(list(str(p1_ship_startrow)+str(p1_ship_startcol+x)))
else:
    while (p1_ship_startrow not in range(0,dim-p1_ship_length+1)) or (p1_ship_startcol not in range(0,dim)):
        yo=raw_input("First Coordinates : ")
        p1_ship_startrow=int(yo[0])-1
        p1_ship_startcol=int(yo[2])-1
    print "Creating the Ship...."
    for x in range(0,p1_ship_length):
        p1_ship_coordinates.append(list(str(p1_ship_startrow+x)+str(p1_ship_startcol)))
    print "Player 1's Ship in place !"

print "Input Form -> ROW COL\n COORDINATES START FROM 1"
print "SETTING UP A SHIP for Player 2....\nStand By..."
for j in range(dim):
    print " ".join(p2_board[j])
p2_ship_length=-9
c=0
while (p2_ship_length<1) or p2_ship_length>dim:
    if c==0:
        p2_ship_length=int(raw_input("Ship Length :"))
    else:
        p2_ship_length=int(raw_input("Ship Length [1-"+str(dim)+"] :"))
p2_orientation=int(raw_input("0->Horizontal\n1->Vertical\nOrientation : "))    # 0= HORIZONTAL SHIP (row -> const) AND  1= VERTICAL SHIP (column -> const)
p2_ship_coordinates=[]
p2_ship_startrow=90
p2_ship_startcol=90
    
if p2_orientation == 0 :
    while (p2_ship_startrow not in range(0,dim)) or (p2_ship_startcol not in range(0,dim-p2_ship_length+1)):
        yo=raw_input("First Coordinates : ")
        p2_ship_startrow=int(yo[0])-1
        p2_ship_startcol=int(yo[2])-1
        if (p1_ship_startrow not in range(0,dim)):
            print "Better Row Required"
        if (p1_ship_startcol not in range(0,dim-p1_ship_length+1)):
            print "Better Column Required"
    print "Creating the Ship...."
    for x in range(0,p2_ship_length):
        p2_ship_coordinates.append(list(str(p2_ship_startrow)+str(p2_ship_startcol+x)))
else:
    while (p2_ship_startrow not in range(0,dim-p2_ship_length+1)) or (p2_ship_startcol not in range(0,dim)):
        yo=raw_input("First Coordinates : ")
        p2_ship_startrow=int(yo[0])-1
        p2_ship_startcol=int(yo[2])-1
    print "Creating the Ship...."
    for x in range(0,p2_ship_length):
        p2_ship_coordinates.append(list(str(p2_ship_startrow+x)+str(p2_ship_startcol)))
    print "Player 1's Ship in place !"
#Let The Games Begin ...
p1_guesses=10
p2_guesses=10
p1_hit_count=0
p2_hit_count=0
while p1_hit_count < p2_ship_length and p2_hit_count < p1_ship_length and p1_guesses>0 and p2_guesses>0:
    print "PLAYER 1\t\tPLAYER 2"
    for i in range(0,dim):
        print " ".join(p1_board[i])+"\t\t"+" ".join(p2_board[i])
    print "HIT COUNT : "+str(p1_hit_count)+"\t\tHIT COUNT : "+str(p2_hit_count)
    print "Guesses Left : "+str(p1_guesses)+"\tGuesses Left : "+str(p2_guesses)
    p1_guess=raw_input("Player 1 CANNON Trajectory : ")
    if p1_guess=="rebirth":                          # CHEAT CODE FOR +3 GUESSES
        print "Cheat Activated !"
        p1_guesses+=3
    elif p1_guess=="finalhint":                       # CHEAT CODE FOR LOCATION REVELATION  
        if p2_orientation==0:
            print "CHEAT ACTIVATED !!!\nIt's in Row "+str(p2_ship_startrow+1)
        else:
            print "CHEAT ACTIVATED !!!\nIt's in Column "+str(p2_ship_startcol+1)
    elif p1_guess=="hinttohde":                       # CHEAT CODE FOR ORIENTATION REVELATION  
        if orientation==0:
            print "CHEAT ACTIVATED !!!\nIt's Horizontally Placed."
        else:
            print "CHEAT ACTIVATED !!!\nIt's Vertically Placed."
    else:
        x=int(p1_guess[0])-1
        y=int(p1_guess[2])-1
        if x not in range(0,dim) or y not in range(0,dim):
            print "You trying to hit moon ?"
            p1_guesses-=1
        elif list(str(x)+str(y)) in p2_ship_coordinates:
            print "\nTHAT'S A HIT !!!"
            h=randint(0,5)
            print comments[h]                        # A nice comment
            p1_hit_count+=1
            p2_board[x][y]='X'
        elif p2_board[x][y]=='X':
            print "You have fired the cannon there already !"
        else:
            print "**blop**\n"
            p2_board[x][y]='X'
            p1_guesses-=1
    print "PLAYER 2"
    p2_guess=raw_input("Player 2 CANNON Trajectory : ")
    if p2_guess=="rebirth":                          # CHEAT CODE FOR +3 GUESSES
        print "Cheat Activated !"
        p2_guesses+=3
    elif p2_guess=="finalhint":                       # CHEAT CODE FOR LOCATION REVELATION  
        if p1_orientation==0:
            print "CHEAT ACTIVATED !!!\nIt's in Row "+str(p1_ship_startrow+1)
        else:
            print "CHEAT ACTIVATED !!!\nIt's in Column "+str(p1_ship_startcol+1)
    elif p2_guess=="hinttohde":                       # CHEAT CODE FOR ORIENTATION REVELATION  
        if orientation==0:
            print "CHEAT ACTIVATED !!!\nIt's Horizontally Placed."
        else:
            print "CHEAT ACTIVATED !!!\nIt's Vertically Placed."
    else:
        x=int(p2_guess[0])-1
        y=int(p2_guess[2])-1
        if x not in range(0,dim) or y not in range(0,dim):
            print "That's not even in the ocean !"
            p2_guesses-=1
        elif list(str(x)+str(y)) in p1_ship_coordinates:
            print "\nTHAT'S A HIT !!!"
            h=randint(0,5)
            print comments[h]                        # A nice comment
            p2_hit_count+=1
            p1_board[x][y]='X'
        elif p1_board[x][y]=='X':
            print "You have fired the cannon there already !"
        else:
            print "**blop**\n"
            p1_board[x][y]='X'
            p2_guesses-=1
if p1_hit_count==p2_ship_length:
    print "PLAYER 1 SUNK PLAYER 2's BATTLESHIP !"
elif p2_hit_count==p1_ship_length:
    print "PLAYER 2 SUNK PLAYER 1's BATTLESHIP !"
else:
    if p1_hit_count>p2_hit_count:
        print "PLAYER 1 GAVE MORE HITS"
    elif p2_hit_count>p1_hit_count:
        print "PLAYER 2 GAVE MORE HITS"
print "Game Over\nThank You for Playing"
     
 
