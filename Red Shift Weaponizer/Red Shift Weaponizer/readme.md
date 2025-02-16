========================================================================
       Red Shift Weaponizer 1.0.0 Project Overview
========================================================================

This program allows the user to generate custom weapons for Red Shift, 
the sci-fi tabletop RPG. It asks the user to input a series of options 
via console using specific inputs to add components.

It walks the user through four selections:
- Frame
- Receiver
- Barrel
- Sight

Some components are incompatible with one another (namely in the explosive
category) and the program will automatically show only compatible choices
for selected components. It will not allow any inputs that are not explicitly
requested so it has a very robust error handling system.

It is also modular: if the DM wants to add new weapon components, all they 
need to do is add them to weaponAssembler.cpp and fill in the array for it.

TODO: - Add a flag system (so if weapons have special properties they can
        be accounted for)
      - Balance the damage rolls; currently some weapons are too OP. Will
        balance them at the DM's discretion
      - Integrate a quick build option with its own function to facilitate
        ... well, quickly building weapon stat blocks
      - Maybe add race/class compatibility? The responsibility for ensuring
        that compatibility is really on the DM, but this *is* a DM tool...
      - More granularity for components (trigger, barrel attachments, grips,
        stocks, etc. )