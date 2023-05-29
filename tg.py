import turtle as t
import time
import random

screen = t.Screen()
screen.title("Keyboard Input Example")
screen.bgcolor("pink")

t.clear()
t.hideturtle()

life = 3
score = 0
start = 0
reset = 0

e=0
f=0
i=0
j=0

def keye(): #청기 올려
    global e
    e = 1  

def keyf(): #청기 내려 
    global f
    f = 1

def keyi(): #백기 올려
    global i
    i = 1

def keyj(): #백기 내려
    global j
    j = 1

def keyspace():
    global start
    start = 1

def resetFunc():
    global start 
    start = 0

def resetvariableFunc():
    global e 
    global f
    global i
    global j
    e = 0
    f = 0
    i = 0
    j = 0

def handle_key():
    screen.onkey(keyi, "i")
    screen.onkey(keye, "e")
    screen.onkey(keyj, "j")
    screen.onkey(keyf, "f")
    screen.onkey(keyspace,"space" )
    screen.onkey(resetFunc, "r")

while True:
    if start == 0:

        t.up()
        t.goto(0,200)
        t.write("press to start game",False,"center",("",30))
        screen.listen()
        handle_key()  

    if start == 1:

        n = 0

        for m in range (0,10):
            
            n += 1

            t.clear()

            k = random.randrange(0,8)

            if k == 0:
                t.up()
                t.goto(0, 200)
                t.write("청기들어",False,"center",("",30))
                
            elif k == 1:
                t.up()
                t.goto(0, 200)
                t.write("청기내려",False,"center",("",30))

            elif k == 2:
                t.up()
                t.goto(0, 200)
                t.write("백기들어",False,"center",("",30))

            elif k == 3:
                t.up()
                t.goto(0, 200)
                t.write("백기내려",False,"center",("",30))

            elif k == 4:
                t.up()
                t.goto(0, 200)
                t.write("청기올리고 백기올려",False,"center",("",30))
            
            elif k == 5:
                t.up()
                t.goto(0, 200)
                t.write("청기올리고 백기내려",False,"center",("",30))
            
            elif k == 6:
                t.up()
                t.goto(0, 200)
                t.write("청기내리고 백기올려",False,"center",("",30))
            
            else:
                t.up()
                t.goto(0, 200)
                t.write("청기내리고 백기내려",False,"center",("",30))
            

            pre = time.time()

            resetvariableFunc()

            while (time.time() - pre < 1):  
                t.goto(0, 0)
                t.write("click",False,"center",("",30))
                screen.listen()
                handle_key()    

            t.clear()

            if k == 0:
                if e == 1 and f == 0 and i == 0 and j ==0:
                    score+=1 
                    t.write(f"{n}회차 성공",False,"center",("",30))
                else:
                    t.write(f"{n}회차 실패",False,"center",("",30))

            elif k == 1:
                if e == 0 and f == 1 and i == 0 and j ==0:
                    score+=1 
                    t.write(f"{n}회차 성공",False,"center",("",30))
                else:
                    t.write(f"{n}회차 실패",False,"center",("",30))

            elif k == 2:
                if e == 0 and f == 0 and i == 1 and j ==0:
                    score+=1 
                    t.write(f"{n}회차 성공",False,"center",("",30))
                else:
                    t.write(f"{n}회차 실패",False,"center",("",30))

            elif k == 3:
                if e == 0 and f == 0 and i == 0 and j ==1:
                    score+=1 
                    t.write(f"{n}회차 성공",False,"center",("",30))
                else:
                    t.write(f"{n}회차 실패",False,"center",("",30))
            
            elif k == 4:
                if e == 1 and f == 0 and i == 1 and j ==0:
                    score+=1 
                    t.write(f"{n}회차 성공",False,"center",("",30))
                else:
                    t.write(f"{n}회차 실패",False,"center",("",30))
            
            elif k == 5:
                if e == 1 and f == 0 and i == 0 and j ==1:
                    score+=1 
                    t.write(f"{n}회차 성공",False,"center",("",30))
                else:
                    t.write(f"{n}회차 실패",False,"center",("",30))
            
            elif k == 6:
                if e == 0 and f == 1 and i == 1 and j ==0:
                    score+=1 
                    t.write(f"{n}회차 성공",False,"center",("",30))
                else:
                    t.write(f"{n}회차 실패",False,"center",("",30))
            
            elif k == 7:
                if e == 0 and f == 1 and i == 0 and j ==1:
                    score+=1 
                    t.write(f"{n}회차 성공",False,"center",("",30))
                else:
                    t.write(f"{n}회차 실패",False,"center",("",30))
            
            time.sleep(1)

            if m == 9:
                t.clear()
                t.up()
                t.goto(0, 200)
                t.write(f"Score : {score}",False,"center",("",30))
                time.sleep(3)
                t.clear()
                resetFunc()