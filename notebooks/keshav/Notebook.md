# Keshav Work Directory

# TA Meeting 2/13/2024
We met with our TA and talked over our initial designs and plans for the project. We also checked out a microcontroller and reworked the shower knob subsystem. We initially were thinking of using a pulley system or a rack and pinion, we now switched to a motor with a hook being mounted onto the handle. 

# Machine Shop Meeting 2/15/2024
Met with the machine shop for the first time. We walked them through our design and got feedback on the setup along with advice for the demo and what kind of motor we should use. We ended up using a NEMA 17 stepper motor. 

# TA Meeting 2/20/2024
Nikhil helped us start with the initial steps of the PCB design and gave us advice on how to start testing components as they came in, along with how to use the devkit to begin programming. We split up the subsystems and since I am covering the transmission and a lot of integration work and these aren't PCB components, I am going to work on the data-driven parts like connection to the microcontroller and the boot circuit.

<img width="154" alt="Screenshot 2024-05-01 at 12 58 42 PM" src="https://github.com/Edidas02/ShowerSync/assets/144846037/d3b3b77e-f1bc-47aa-9f66-432e27e81143">
<img width="235" alt="Screenshot 2024-05-01 at 1 04 09 PM" src="https://github.com/kdandu2/ShowerSync/assets/144846037/4ca6e376-87c4-41e5-b9c6-767e692920eb">



# TA Meeting 3/5/2024
We are almost done routing the PCB and it should be fine for the second wave. I have begun using tutorials online to begin testing with the transmission subsystem. We ended up switching to a wifi access point since it seems to be more reliable from everything I have seen online. I have also got an initial version of the site up. 

# Spring break 
As a group we completed our PCB, it passed audit and we plan to order with the 2nd wave.
<img width="761" alt="Screenshot 2024-05-01 at 12 48 25 PM" src="https://github.com/Edidas02/ShowerSync/assets/144846037/66c74060-57e2-4596-bb43-2ab635cdbb8f">


# TA Meeting 3/19/2024
We have sent in our PCB to be ordered. I am working on getting the site along with gaining a better understanding of how to integrate other subsystems since the website requires a loop to constantly be running and check if there is an input. Setup initial input testing with press buttons and LEDs on the breadboard that reacts. I will try to do string inputs and output next. 
<img width="289" alt="Screenshot 2024-05-01 at 12 48 48 PM" src="https://github.com/Edidas02/ShowerSync/assets/144846037/8a749427-dcb8-419b-a044-a059cb40db97">


# TA Meeting 3/26/2024
Got the version of the site with the LEDs and buttons to work properly. I also helped out with the algorithm to get the handle to move based on inputted temperature and since that was simplified down to a function call I will try to integrate it with the website over the coming week. 

# TA Meeting 4/2/2024 
Informed by our TA that our PCB order had been accidentally deleted and that they would separately review and order one for us. We were given changes by the TA Jason, to help us change our PCB before ordering. There were many issues with how I was trying to integrate the handle code with the site, I could not just call it as a function call since then the site basically goes down and there is no way to make the stop button, so I have started reworking the entire structure of the code to work together. 

# TA Meeting 4/9/2024 
Successfully got the code to work and have begun implementing a stop button. There are some issues with the rotation and the motor not being strong enough so I am also testing if adjustments to the algorithm such as making it step more times per call would make the rotations smoother. 

# TA Meeting 4/16/2024 
PCB came in and the other two are working on soldering it while I am fine-tuning the Stop button and other functionality with the site and the handle. There are many bugs coming up with trying to make the rotation of the handle smoother. 

# FINAL DEMO
Demoed on 4/25/2025. The PCB was not functional due to issues with components use for voltage regulation. The breadboarded prototype worked entirely. 


