# Plant Palace: Demo Flow & Script

This document outlines the 30-minute demo flow, speaker scripts, and technical cues for the COS214 Final Project: Plant Palace Nursery System.

##  Demo Details

* **Total Time:** 30 Minutes
* **Team:**
    * **You (Speaker):** Intro, Other UMLs, Live UI Simulation, Conclusion
    * **Johan (Speaker):** System Architecture & Design Patterns
    * **Zoe (Speaker):** Code Documentation (Doxygen)
    * **Bulelani (Speaker):** Development Practices (Git Workflow)
    * **Connor (Driver):** Controls slides and the live GUI application.

---

## 1. Introduction (3 Minutes)

* **Speaker:** You
* **Driver:** Connor

#### 🕹️ [Connor's Cues]
* Show Slide 1 (Title) as the presentation begins.
* Advance to Slide 2 when the speaker mentions the project goal.
* Advance to Slide 3 for the agenda.

####  slides
* **Slide 1: Title Slide**
    * Title: Plant Palace Nursery System
    * Course: COS214 Final Project
    * Team Name: [Your Creative Team Name]
    * Members: [Your Name], Johan, Zoe, Bulelani, Connor
* **Slide 2: The Project Goal**
    * **Objective:** "Design and implement a flexible, maintainable, and scalable Plant Nursery Simulator in C++."
    * **Core Task:** "Model the three main areas of a working nursery:"
        * The Greenhouse & Plant Lifecycle
        * The Staff & Care Routines
        * The Customers & Sales Floor
    * **Key Constraint:** "Use object-oriented principles and at least 10 design patterns to manage complexity."
* **Slide 3: Demo Agenda**
    1.  Introduction (Me)
    2.  System Architecture & Patterns (Johan)
    3.  Behavioural Modelling (Me)
    4.  Live System Simulation (Me & Connor)
    5.  Documentation (Zoe)
    6.  Development Workflow (Bulelani)
    7.  Conclusion & Q&A

#### 🎤 Your Speech (Intro)
> "Good morning everyone. My name is [Your Name], and on behalf of my team—Johan, Zoe, Bulelani, and Connor—I'd like to welcome you to the demo of our COS214 final project, the Plant Palace Nursery System.
>
> The goal of this project was to design and implement a complex, object-oriented simulation of a plant nursery in C++17. The specification required us to model the three core areas of the business: the **Greenhouse** where plants grow, the **Staff** who care for them, and the **Customers** on the sales floor.
>
> A key requirement was to use design patterns—at least 10 of them—to manage this complexity and build a system that is flexible, maintainable, and scalable, just like a real nursery.
>
> Today, we'll walk you through our system in this order. [Gesture to Slide 3].
>
> To start, I'll hand over to Johan, who will discuss our core architecture and how we used design patterns to build it."

---

## 2. System Architecture & Design Patterns (8 Minutes)

* **Speaker:** Johan
* **Driver:** Connor

#### 🕹️ [Connor's Cues]
* Advance to Slide 4. Be ready to pan/zoom on the class diagram as Johan points out the main zones.
* Advance to Slide 5 for the Facade pattern.
* Advance to Slide 6 for Composite/Iterator.
* Advance to Slide 7 for Observer.
* Advance to Slide 8 for Adapter.

#### slides
* **Slide 4: System Class Diagram**
    * A high-resolution image of your complete system class diagram.
* **Slide 5: Key Pattern: Facade (Sales)**
    * Show the partial class diagram for the Sales Facade from `design-patterns-report.md`.
    * Rationale: "Provides a single entry point for complex sales operations (FR25)."
* **Slide 6: Key Patterns: Composite & Iterator (Greenhouse)**
    * Show the partial diagrams for Composite and Greenhouse Iterator from `design-patterns-report.md`.
    * Rationale: "Represents the part-whole greenhouse hierarchy (FR10) and provides uniform traversal for growth ticks (FR12, FR26)."
* **Slide 7: Key Pattern: Observer (Plant Lifecycle)**
    * Show the partial diagram for Observer from `design-patterns-report.md`.
    * Rationale: "Decouples plants (Subjects) from staff and stock items (Observers) (FR13, FR14). Notifies observers of state changes, like 'care needed' or 'ready for sale' (FR27)."
* **Slide 8: Key Pattern: Adapter (File I/O)**
    * Show the partial diagram for the File Adapter from `design-patterns-report.md`.
    * Rationale: "Isolates inventory logic from specific file formats (CSV/TXT) (FR8, FR9)."

#### 📋 Johan's Outline
* **Introduce the Class Diagram (Slide 4):**
    * Start with the high-level class diagram. Point out the three main zones of the system (Greenhouse/Plant, Sales/Inventory, Staff/Customer).
    * State that the system implements over 10 patterns as required, and you will highlight 4 critical ones from the report.
* **For each of the 4 key patterns (Slides 5-8), explain:**
    * **1. What is it?** (e.g., "First, we used the **Facade** pattern.")
    * **2. Why (The Rationale)?** (e.g., "We chose this to solve FR25. The sales process is complex—it involves checking inventory, building an order, and processing payments. The Facade provides a single, simple entry point for the UI, hiding all that complexity.")
    * **3. Where (The Participants)?** (Point to the diagram: "Our `SalesFacade` class coordinates the `Inventory`, `OrderBuilder`, and `PaymentProcessor` subsystems.")
* **Repeat this logic for:**
    * **Composite + Iterator:** (Why: To handle the nested greenhouse structure (FR10, FR12). How: `GreenhouseComponent` is the interface, `GreenhouseBed` is the composite, and `PlantInstance` is the leaf. The `GreenhouseIterator` lets us traverse this whole structure easily for growth ticks (FR26).)
    * **Observer:** (Why: To decouple our system (FR13). How: The `PlantInstance` is the Subject. When its state changes (e.g., it needs water, or becomes 'Mature'), it notifies its Observers, like `Staff` (who adds a care task) and the `StockItem` (which updates its sale availability, FR27).)
    * **Adapter:** (Why: To load/save inventory without locking `Inventory` to one file type (FR8, FR9). How: The `Inventory` class only knows the `FileAdapter` interface. We then created `CSVAdapter` and `TXTAdapter` that 'adapt' our `CSVReaderWriter` to fit that interface.)

---

## 3. Behavioural Modelling (2 Minutes)

* **Speaker:** You
* **Driver:** Connor

#### 🕹️ [Connor's Cues]
* Advance to Slide 9.

#### slides
* **Slide 9: Behavioural UML Diagrams**
    * A grid showing screenshots of your 5 other UML diagrams.
    * Label them clearly:
        * State Diagram
        * Activity Diagram
        * Sequence Diagram
        * Object Diagram
        * Communication Diagram

#### 🎤 Your Speech (Behavioural Modelling)
> "Thanks, Johan. As part of our initial design for Practical 5, we also created several other UML diagrams to model the system's *behaviour*.
>
> On this slide, you can see our **State Diagram**, which models the plant lifecycle from Seed to Dead. We also have an **Activity Diagram** for the sales workflow, and **Sequence** and **Communication** diagrams to map out object interactions.
>
> We won't go into detail on these, but they were essential for planning the logic that you're about to see in the live simulation."

---

## 4. Live System Simulation (10 Minutes)

* **Speaker:** You
* **Driver:** Connor

#### 🕹️ [Connor's Cues]
* **Start:** Switch from slides to the live GUI application.
* **Flow 1:**
    1.  Navigate to the **System Admin** tab.
    2.  Click **"Load Inventory"**.
    3.  Select the demo `.csv` file and click 'Open'.
    4.  In the 'Plant Prototypes' section, click **"Create New Prototype"**.
    5.  In the dialog:
        * Enter Name: "Bonsai"
        * Select Water Strategy: "Sparse Watering"
        * Select Fertilize Strategy: "Slow Release Fertilizer"
        * Click **"Add Prototype"**.
    6.  Back in the main window:
        * Select "Bonsai" from the prototype list.
        * Select "Main Greenhouse" from the bed list.
        * Enter a price (e.g., "150").
        * Click **"Add to Greenhouse"**.
* **Flow 2:**
    1.  Navigate to the **Greenhouse Management** tab.
    2.  Expand the greenhouse beds to reveal the new "Bonsai" plant.
    3.  Click on the "Bonsai" plant to select it. (Pause to let the details panel load).
    4.  Click the **"Run Growth Tick"** button. (Pause for log update).
    5.  Click "Run Growth Tick" several more times, until the log shows the plant is "Mature" and "Ready for Sale".
* **Flow 3:**
    1.  Click **"Run Growth Tick"** one more time, until the log shows "Care Required: Needs Water".
    2.  Navigate to the **System Admin** tab.
    3.  Go to the "Staff Tasks" section.
    4.  Select "Staff 1" from the dropdown to show the "Water Plant" task in their queue.
    5.  Click **"Process Next Task"**. (Pause for task to disappear).
    6.  Navigate back to the **Greenhouse Management** tab.
    7.  With the "Bonsai" still selected, go to the "Water Strategy" radio buttons.
    8.  Click **"Frequent"** to change the strategy.
* **Flow 4:**
    1.  Navigate to the **Messaging** tab.
    2.  Select Sender: "Staff 1".
    3.  Select Receiver: "Customer 1".
    4.  Type message: "Your Bonsai is ready".
    5.  Click **"Send Message"**.
    6.  Navigate to the **Sales & Inventory** tab.
    7.  Point mouse to the main inventory list (showing the "Bonsai" as available).
    8.  Go to the "Create Order" sub-tab.
    9.  Select "Customer 1" from the "Select Customer" dropdown.
    10. Select "Bonsai" from the "Select Item" dropdown.
    11. Click **"Add to Order"**.
    12. Click **"Finalise Order"**. (Pause for log update).
    13. Go back to the "Inventory List" sub-tab (show that the Bonsai is gone).

#### 🎤 Your Speech (Live Simulation)
> "Okay, this is the main interface for the Plant Palace Simulator. The system is organized into tabs: Messaging, Greenhouse Management, Sales & Inventory, and System Admin. The log at the bottom timestamps key actions.
>
> **Flow 1: System Admin & Setup (Adapters & Prototypes)**
>
> "Before we can do anything, we need to load our nursery. We'll start in the **System Admin** tab.
>
> "Our system uses the **Adapter** pattern to load inventory. As you can see, we can choose between `.csv` and `.txt` files. We'll load the demo CSV.
>
> *(After load)* "Great. The system is now populated. This tab also manages our **Plant Prototypes**. This pattern lets us define 'template' plants. We'll quickly create a new 'Bonsai' prototype, assigning it a default 'Sparse Watering' **Strategy** and 'Slow Release' fertilizing **Strategy**.
>
> "Now that we have this 'Bonsai' prototype, we can clone it into the greenhouse. We just select the prototype, choose the 'Main Greenhouse' bed, set a price, and add it. A new `PlantInstance` is created from the prototype and added to the greenhouse **Composite**."
>
> **Flow 2: Greenhouse Management (Composite, Iterator, Observer, State)**
>
> "Now let's see that plant. In the **Greenhouse Management** tab, we can browse the **Composite** structure. As we expand the beds, you can see we have nested beds and individual plants.
>
> "Here is the 'Bonsai' we just added. When we select it, the right panel updates with its live data. This is the **Observer** pattern at work; the UI observes the plant. We can see its vitals and its current **State**, which is 'Growing'.
>
> "Now, let's simulate time passing. By clicking 'Run Growth Tick', we use a **Greenhouse Iterator** to visit every plant in the composite and apply growth. You can see the plant's vitals changing in the log.
>
> "Let's run a few more ticks. ... Okay, notice the log? The plant's state changed to 'Mature', and its 'Sale Readiness' is now 'True'. This state change was also *observed* by its corresponding `StockItem`, so it's now available for sale."
>
> **Flow 3: Staff & Plant Care (Command, Observer, Strategy)**
>
> "Let's run another tick. ... Ah, the log now says 'Care Required: Needs Water'. The plant's `WaterStrategy` determined it was thirsty and, as a Subject, it *notified* its **Observers**.
>
> "If we go to the **System Admin** tab and look at 'Staff Tasks', we can see 'Staff 1' is observing that plant, so a 'Water Plant' task appeared in their queue. This is the **Command** pattern. The request is an object in a queue.
>
> "When we process the next task, the command is executed, the plant is watered, and the task is removed from the queue.
>
> "Back in the **Greenhouse** tab, we can also change the plant's care **Strategy** at runtime. We'll select the Bonsai and change its Water Strategy from 'Sparse' to 'Frequent'. Now, this plant instance will use a different watering algorithm."
>
> **Flow 4: Messaging & Sales (Mediator, Facade, Builder, Iterator)**
>
> "While we're here, let's use the **Messaging** tab. This system uses the **Mediator** pattern to decouple staff and customers. We'll send a message from 'Staff 1' to 'Customer 1' saying 'Your Bonsai is ready'.
>
> "Finally, let's sell that Bonsai. In the **Sales & Inventory** tab, the inventory list—which is populated by an **Inventory Iterator**—shows our Bonsai is listed as 'Available'.
>
> "In the 'Create Order' sub-tab, we'll select 'Customer 1'.
>
> "Now, from the 'Select Item' dropdown, we'll add the 'Bonsai' to the order. This dropdown only shows items that are *actually* available for sale, thanks to the Observer and Iterator patterns working together.
>
> "When we click 'Finalise Order', we are calling our **Sales Facade**. This one method call handles everything: it uses an **Order Builder** to create the order, tells the `PaymentProcessor` to charge the customer, and updates the `Inventory` to remove the item. As you can see, the order is logged, and if we check the inventory list, the Bonsai is gone."
>
> "That concludes the main simulation flow. As you can see, the patterns work together to create a decoupled and flexible system. Now, I'll pass it over to Zoe to discuss our documentation."

---

## 5. Code Documentation (2.5 Minutes)

* **Speaker:** Zoe
* **Driver:** Connor

#### 🕹️ [Connor's Cues]
* Switch from the GUI to the web browser showing the Doxygen HTML output.
* Navigate to a key class page, like `PlantInstance` or `SalesFacade`, as Zoe begins.
* Scroll down to show method details and parameters as she mentions them.
* Click on a collaboration diagram if she points it out.

#### slides
* **Slide 10: Code Documentation (Doxygen)**
    * *This slide is a backup in case the live Doxygen demo fails.*
    * A screenshot of the Doxygen HTML output.
    * Bullet points: "Generated documentation from C++ comments", "Documents all classes, methods, and complex logic", "Auto-generates collaboration diagrams".

#### 📋 Zoe's Outline
* Explain that a project requirement was comprehensive documentation.
* State that the team used **Doxygen** to generate this HTML documentation directly from our C++ comments.
* (While Connor shows the live Doxygen page).
* Point out key features:
    * How to navigate to a class (e.g., `SalesFacade`).
    * Show how the public methods, parameters, and descriptions are clearly listed, following C++ documentation standards.
    * Mention the auto-generated class diagrams, which help visualize dependencies.
    * State that all team members were responsible for documenting their code.

---

## 6. Development Workflow (2.5 Minutes)

* **Speaker:** Bulelani
* **Driver:** Connor

#### 🕹️ [Connor's Cues]
* Switch from Doxygen to the team's GitHub repository page.
* Navigate to the "Pull Requests" tab and click "Closed" to show the PR history.
* (Optional) Click on the "Insights" > "Contributors" tab to show the commit graph.

#### slides
* **Slide 11: Development Practices (Git & GitHub)**
    * *This slide is a backup in case the live GitHub demo fails.*
    * A screenshot of your GitHub repo's "Pull Requests" tab (showing closed PRs).
    * Bullet points: "Git used for all version control", "Feature-branch workflow with Pull Requests", "Regular commits from all team members", "Automated Unit Testing for key logic".

#### 📋 Bulelani's Outline
* Explain that the project required using **Git** and **GitHub** for version control.
* Describe the team's branching strategy (e.g., "We used a feature-branch workflow. Developers would create a new branch, implement their feature, and then open a Pull Request for review.").
* (While Connor shows the GitHub page) Point to the closed Pull Requests and the commit history, noting that all members contributed regularly, meeting the 10-commit requirement.
* Mention the use of **Unit Tests**: "We also implemented automated unit tests to ensure key functionalities, like our patterns and business logic, worked as expected. Every member contributed to writing these tests."
* (Optional) If you did the bonus: "We also set up a GitHub Actions pipeline to automatically lint and test our code on every commit."

---

## 7. Conclusion & Q&A (2 Minutes)

* **Speaker:** You
* **Driver:** Connor

#### 🕹️ [Connor's Cues]
* Switch from GitHub back to the presentation.
* Advance to the final slide (Slide 12).

#### slides
* **Slide 12: Thank You**
    * Title: Thank You
    * Message: Questions?

#### 🎤 Your Speech (Conclusion)
> "Thank you, Bulelani and Zoe.
>
> In summary, our Plant Palace system successfully models a complex nursery using C++17 and object-oriented principles. By applying design patterns like **Facade**, **Composite**, **Observer**, and **Adapter**, we built a system that is flexible, maintainable, and meets all the project requirements.
>
> This project was a great experience in collaborative software development.
>
> Thank you for your time. We would now like to open the floor for any questions."
