Vision:
	This project is to accelerate the usual grind in my office work. Hence the name "AccGrind"  (ACCelerated GRIND)
	I can focus on real thought provoking work if the usual rut work can be either made faster or best automated.
	Why I want to do this project:
		# I become more efficient
		# Concieving the project allows me to use my brains
		# Executing the project allows me to sharpen my skills
		# I reduce the wasted effort in my routine day 2 day effort
		# The knowledge about the application -- gets depicted in the code rather than just in my mind, helping new resource onboarding
		# Concieving this project also gives a direction to my thoughts
	Why I DONOT want to do this project:
		# If I become very efficient in rut work, more of rut work will slide towards me (based on experience).
		# As per the team dynamics, it does not add value to the team perception, rather makes the team more fearful.
		# Nolio adoption will make the deployment task automation - duplicate work.
		# If I increase the productivity of the team much more, it increases the probability of decreasing the size of the team -- that includes me.
	Conclusion:
		Improving my days to day work has +ve impact on my daily routine.
		Executing this project will improve my technical skills to unprecended levels.
		I have a basic principle, "I am ready to do any kind of work, that makes my office projects successful". I am paid to do that.
		While I increase the team efficiency, if management decided to let go of me, its's management's loss.
		I am taking on this project, ignoring the political side effects of this work (i.e. increased rut work).

Let loose the imagination:
		This has the potential to a generic application management framework which is usable across organizations
		It makes the lives of developers easier and makes them more productive
		Challenges to this vision - to become more adopted:
		# Onboarding to this application will involve a learning curve that is going to be quite steep
		# This application has to scale the challenge -- Not developed here is not good.

Phase I
Typical work items that are a repeated effort and are monotonous are
	#  Developer tasks
		## fetching get-latest in sourceControl
		## building latest code
		## setup of debug environment -- putting the developed code into DEV env and running the services.
		## service monitoring on DEV environments
		## having to run test/integration programs again and again. It should be as easy as a couple of clicks / keyboard keystrokes to repeat.
	#  Release tasks
		## downloading build artifacts from build server
		## Deployment of MSIs on SIT and UAT environment
		## Autosys script release
		## service monitoring on SIT/UAT environments
	#  Getting application sign-offs for release process (Data analysis)
		## Running UAT batches
		## Anaysis of issues
		## Getting issue explains

Technical Feature goals:
# It must allow for plug and play parts that can be extended later
# It has to be light to build and extend

Potential tool sets:
# Python	-- quick prototyping
# C++		-- I know how to code in this
# Java/scala		-- just because I wish to learn it

Target Environment:
	Release tasks
		Windows	2008 Server
		Linux	Ubuntu, Redhat 
	Development environment
		Windows 7
		Linux	Ubuntu, Redhat 

Challenges:
Need to understand Rest API usage -- to integrate with other components
Need to understand windows API
Need to understand Linux API

Initial design thoughts:
The application is envisioned as core and plugin.
The core allows the plugins to register the functionality they offer.
The plugins support good citizenship -- they comply with minimum functional requirement.
The core is responsible for text handling and passing on the user input to the plugin.
The plugin implements the desired functionality.
For remote actions, agent in the target machine is a sensible design.
For each plugin loaded, the logging is for the file 'plugin-name.log' -- how do I get it?
