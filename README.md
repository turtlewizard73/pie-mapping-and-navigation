# ros-rob-project-mapping
Repo for Robotrendszerek laboratórium project

## Project description
- Navigációs stack behangolása bonyolult szimulációs környezetben
- Egy bonyolult szoba / épület feltérképezése és autonóm navigáció a navigációs stack használatával
- Mozgó akadályok szimulációja (pl ember, állat)

## Github workflow
How to add new functionality to the stack:
1. Create feature/fix branch from **main**
2. Develop feature set
3. Test
4. If testing was successful --> create **PR**
5. **PR** has to be tested by other project member
6. If it was successful --> squash merge onto **main**

Branch types:
- **main**: main branch, "protected"
- **feature**: feature branch, for adding new features, or expanding existing features
    - example name: feature-lidar-xacro
- **fix**: fix branch
    - example name: fix-robot-color

## El Plan
Sorrend féle valami, trello?  
**Nulladik iteráció**  
-> cél: neki tudjunk kezdeni a munkának
-> kell: egy meeting
1. github workflow megbeszélés
2. használjunk-e trellot a feladatokhoz?
3. ki mivel szeretne foglalkozni? -> taskok szét osztása érdeklődési körök szerint
4. írjunk e minden readme-t angolul (illene)
    - szóval lehet már ezt az egészet angolul kellett volna írnom

**Első iteráció - basic mapping**   
-> cél: legyen térkép  
-> kell: mapping package + lidar + robot model + szoba model
1. basic mapping összerakás turtle botra
2. mapping stack (jelentsen ez bármit is) - főként utánanézni fasza packageknek
3. hardwerek szimulációja (doboz rajta egy lidarral)
    - robot urdf (nagyon alap doboz)
    - lidar -> xacro
4. alap launch file ami összerántja az egészet
    - külön launch robotnak
    - külön launch word + gazebo
    - esetleg egy rvizes config file (utánanézni)
5. map modellezés (legyen valami szoba amiket fel lehet térképezni)

**Második iteráció - navigáció**  
-> cél: robot térképen el tudjun jutni valahova  
-> kell: navigációs package + legyen map
1. basic navigáció turtle botos mintán
2. kicsivel jobb robot leírás -> xacro
    - kerekek a lényegek
3. kicsivel jobb szoba modell
    - bonyolultabb geometria
    - akadályok!
4. talán itt jön be az odometria is
    - ezt szimulációban annyira nem vágom,  
    de illene szimulálni főleg kovariancia miatt ( nem tudom mi az)

**Harmadik iteráció - modellek véglegesítése - PÁRHUZAMOSÍTHATÓ**  
-> cél: legyen egy fasza robot modell + szoba  
-> kell: végtelen modellezés plusz valami fizikai kiindulási alap
1. bonyolultabb szoba word modell
2. bonyolultabb robot
    - milyen robot? turtle, vagy 3d scannelve valami
3. térde imára, hogy itt már nem romlik el a stack

**Negyedik iteráció - mozgó akadályok**  
-> cél: local costmap-en látszódjanak mozgó akadályok  
-> kell: tudjunk navigálni a globális mapen
Ez a rész annyira nem világos
1. kell lokális térképezés
    - ha van egy globális mapünk akkor rá tudjuk rakni a dinamikusan megjelenő akadályokat
2. costmap-ek
    - lokális és globális
3. itt valszeg lehet meghal az egész navigációs stack
4. az elejétől amúgy figyelembe kellene venni a lokális és globális problémát

**Utolsó iteráció - véglegesítés**  
-> cél: leadható legyen
1. README megírás
2. tesztelés  
3. bugok kigyomlálása


## Sources
Add sources, links, documentations, any useful information, that might be useful or needed.
1. Plan 3d scanning:
    - **Meshroom**
        - https://alicevision.org/#meshroom
        - https://www.youtube.com/watch?v=yKbyVDK2Ep8
        - Uses images
    - **RealityCapture**
        - https://www.capturingreality.com/
        - https://www.youtube.com/watch?v=i8AdX6OCvHg
        - Images and video
    - by using equipment provided by karman studio shoot video or take pictures from robot, then make a 3d model by using some software. Touch up the generated model and import it into gazeboo.

2. tutel bot stuff
https://emanual.robotis.com/docs/en/platform/turtlebot3/overview/#notices