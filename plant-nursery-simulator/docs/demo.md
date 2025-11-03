# Plant Palace: Demo Flow & Script

This document outlines the 30-minute demo flow, speaker scripts, and technical cues for the COS214 Final Project: Plant Palace Nursery System.

##  Demo Details

* **Total Time:** 30 Minutes
* **Team:**
    * **Adriano (Speaker):** Intro, Other UMLs, Live UI Simulation, Conclusion
    * **Johan (Speaker):** System Architecture & Design Patterns
    * **Zoe (Speaker):** Code Documentation (Doxygen)
    * **Bulelani (Speaker):** Development Practices (Git Workflow)
    * **Connor (Driver):** Controls slides and the live GUI application.

---

## 1. Introduction (3 Minutes)

* **Speaker:** Adriano
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
    * Members: Adriano, Johan, Zoe, Bulelani, Connor
* **Slide 2: The Project Goal**
    * **Objective:** "Design and implement a flexible, maintainable, and scalable Plant Nursery Simulator in C++."
    * **Core Task:** "Model the three main areas of a working nursery:"
        * The Greenhouse & Plant Lifecycle
        * The Staff & Care Routines
        * The Customers & Sales Floor
    * **Key Constraint:** "Use object-oriented principles and at least 10 design patterns to manage complexity."
* **Slide 3: Demo Agenda**
    1.  Introduction (Adriano)
    2.  System Architecture & Patterns (Johan)
    3.  Behavioural Modelling (Adriano)
    4.  Live System Simulation (Adriano & Connor)
    5.  Documentation (Zoë)
    6.  Development Workflow (Bulelani)
    7.  Conclusion & Q&A

#### 🎤 Adriano's Speech (Intro)
> "Good morning everyone. My name is Adriano, and on behalf of my team—Johan, Zoë, Bulelani, and Connor—I'd like to welcome you to the demo of our COS214 final project, the Plant Palace Nursery System.
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
* Show Slide 5 (System Architecture Overview) as Johan starts.
* Advance to Slide 6 for the large class diagram when mentioned.
* Advance to Slides 7–8 for the Sales Facade.
* Advance to Slides 9–10 for Composite & Iterator (Greenhouse).
* Advance to Slides 11–12 for Observer (Plants & Staff).
* Advance to Slides 13–14 for Adapter (File I/O).
* Advance to Slides 15–16 for Command (Plant Care).
* Advance to Slides 17–18 for Chain of Responsibility (Care Routing).
* Advance to Slides 19–20 for Mediator (Floor Coordination).
* Advance to Slide 21 for Builder (Orders).

#### slides
* **Slide 5: System Architecture Overview**
    * Greenhouse (Composite, Iterator, State)
    * Staff (Observer, Command, COR, Mediator)
    * Sales (Builder, Facade, Adapter)
* **Slide 6: Large Class Diagram**
* **Slide 7: Facade Pattern — Sales**
    * Intent: Unified access to inventory/order/payment subsystems
    * Why: Centralized API, simplifies operations; FR25
* **Slide 8: Sales Facade Class Diagram**
* **Slide 9: Composite & Iterator — Greenhouse**
    * Intent: Traverse beds uniformly; Why: Hierarchical operations; FR10–FR12, FR26
* **Slide 10: Greenhouse Composite Class Diagram**
* **Slide 11: Observer Pattern — Plants & Staff**
    * Intent: Notify on plant health/availability changes; Why: Automates sync; FR13–FR14, FR27
* **Slide 12: Plant Instance Observer Class Diagram**
* **Slide 13: Adapter Pattern — File I/O**
    * Intent: Switch TXT/CSV seamlessly; Why: Extensible I/O; FR8–FR9
* **Slide 14: I/O Adapter Class Diagram**
* **Slide 15: Command Pattern — Plant Care**
    * Intent: Encapsulate actions; Why: Queuing/history; FR18–FR19
* **Slide 16: Plant Care Command Class Diagram**
* **Slide 17: Chain of Responsibility — Care Routing**
    * Intent: Chain of handlers; Why: Extensible routing; FR20–FR21
* **Slide 18: COR Care Requests Class Diagram**
* **Slide 19: Mediator Pattern — Floor Coordination**
    * Intent: Centralize communications; Why: Reduce coupling; FR22–FR23
* **Slide 20: Floor Mediator Class Diagram**
* **Slide 21: Builder Pattern — Orders**
    * Intent: Step‑wise construction; Why: Optional components; FR24

#### 🎤 Johan's Speech (System Architecture & Design Patterns)
> Thanks Adriano.
>
> I’ll be walking you through our nursery system, its architecture and the design patterns that hold it together. I’ll start with a quick overview of the system structure, then move to the large class diagram, and finally highlight some of the key patterns. Throughout, I’ll keep drawing the link between the Greenhouse, Inventory, and Sales: the core connection that keeps the system alive and in sync. (Slide 5)
>
> Our architecture is divided into three collaborating zones. The Greenhouse manages plants and their lifecycles. The Staff zone handles care, coordination, and communication. And the Sales zone manages customer interaction, ordering, and file I/O. Each zone uses a cluster of design patterns. The Greenhouse relies on Composite, Iterator, Prototype and State to model its structure and lifecycle; the Staff zone uses Observer, Command, Chain of Responsibility, and Mediator for care and communication; and the Sales zone applies Builder, Facade, and Adapter to streamline ordering and integration. Together, these patterns keep the greenhouse reality and the storefront view perfectly aligned. (Slide 5)
>
> Let’s move to the large class diagram. At the centre is the Greenhouse structure. The Composite pattern models beds and plants as a hierarchy: every node, whether a bed or a plant, can receive the same command. The Iterator pattern allows us to traverse that hierarchy without exposing internal details, letting controllers easily perform operations like growth ticks across all plants. Each PlantInstance is also the context for our State pattern. Plants transition through seed, growing, mature, withering, and dead states, each defining how the plant behaves: when it’s ready for sale, how it reacts to care, and when it signals for staff attention. (Slide 6)
>
> This is where the Inventory ties in. Every stock item in Inventory is linked directly to a living plant in the greenhouse. Through Observer, stock entries automatically reflect their plant’s state: when a plant becomes market‑ready, it’s marked as available; when it dies or is sold, it’s removed. The result is instant, automatic synchronisation between greenhouse and storefront. Two more patterns appear here even though they don’t have their own slides later on: Strategy lets each plant use a suitable care algorithm—for example, unique watering or fertilising methods per species or lifecycle state—and Prototype ensures new plants are created consistently by cloning pre‑registered templates. It’s data‑driven, so new species can be added dynamically without changing the code. (Slide 6)
>
> The Sales Facade unifies the sales workflow: checking stock, building orders, finalising payments, and removing sold items. Without it, clients would have to call multiple subsystems in sequence. With it, everything happens through one clean interface. When a purchase completes, the facade updates the exact stock items tied to specific plants, keeping both systems aligned to the instance level. (Slides 7–8)
>
> Composite and Iterator in the Greenhouse. Our greenhouse uses a hierarchy, so Composite lets us treat beds and plants uniformly. The Iterator provides a reusable way to traverse the structure without mixing traversal logic into controllers. Inventory also uses its own iterator to browse both plants and regular stock items like pots or soil, unifying data access across the system. (Slides 9–10)
>
> Observer for Plants and Staff. Whenever a plant’s state changes—say moisture drops or it becomes ready for sale—observers are notified. Staff observers create actionable care tasks, while stock observers update availability in the storefront. We use a push model so observers receive only the necessary event data. When a plant is removed, observers detach cleanly to avoid dangling references. (Slides 11–12)
>
> Adapter for File I/O. The Adapter pattern allows the system to import and export inventory in multiple formats, TXT, CSV, or future options like JSON, without changing the core logic. When data is loaded, the adapter reconstructs stock items and, for plants, reconnects them to the greenhouse using their prototypes and state information. The greenhouse and storefront join seamlessly as soon as data enters the system. (Slides 13–14)
>
> Command for Plant Care. Plant‑care actions such as watering or fertilising are encapsulated as Commands. Staff can queue or execute them independently of timing or order. Each command knows its target plant and runs care logic based on the plant’s current state. Any resulting state change automatically triggers observer updates, keeping inventory and greenhouse aligned. (Slides 15–16)
>
> Chain of Responsibility for Care Routing. Different care requests pass through a chain of handlers: watering, fertilising and so on. Each handler processes requests it understands or passes them along. This allows new care types to be added easily. The flow—request → handler → plant → observers → storefront—keeps the system flexible and consistent. (Slides 17–18)
>
> Mediator for Floor Coordination. On the shop and greenhouse floors, communication between staff and customers is routed through a Mediator: a central “radio” that prevents every colleague from needing direct references to one another. Messages go to the mediator, which forwards them to the right recipient. This design scales well and makes it easy to add new colleague types later. (Slides 19–20)
>
> Builder for Orders. Orders aren’t just lists of items. Builder allows complex, step‑by‑step construction—from quick one‑item sales to pre‑built baskets. The Sales Facade either guides the builder with preset recipes or lets the user assemble items manually. Once payment is finalised, the facade removes the corresponding stock entries and detaches their plants from the greenhouse, maintaining a clean, traceable chain from plant to order. (Slide 21)
>
> Stepping back, every pattern plays a focused role: Composite structures the greenhouse. Iterator handles traversal. State drives plant behaviour. Observer keeps all systems in sync. Command and Chain of Responsibility manage care actions. Mediator simplifies communication. Builder, Adapter, and Facade streamline the customer experience and integration. Together, they form a modular system where changes in one area don’t break another. When a plant becomes ready, the storefront shows it instantly. When a sale happens, that specific plant is removed from the greenhouse. And when data is imported, new plants can be simulated immediately. These patterns aren’t academic: they’re what keep our system consistent, flexible, and alive. 
> 
> Thank you. Back to Adriano.

---

## 3. Behavioural Modelling (2 Minutes)

* **Speaker:** Adriano
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

#### 🎤 Adriano's Speech (Behavioural Modelling)
> "Thanks, Johan. As part of our initial design for Practical 5, we also created several other UML diagrams to model the system's *behaviour*.
>
> On this slide, you can see our **State Diagram**, which models the plant lifecycle from Seed to Dead. We also have an **Activity Diagram** for the sales workflow, and **Sequence** and **Communication** diagrams to map out object interactions.
>
> We won't go into detail on these, but they were essential for planning the logic that you're about to see in the live simulation."

---

## 4. Live System Simulation (10 Minutes)

* **Speaker:** Adriano
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

#### 🎤 Adriano's Speech (Live Simulation)
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
> "btw, we can also add for example a purple pot from the add item in system admin." 
>
> **Flow 2: Greenhouse Management (Composite, Iterator, Observer, State)**
>
> "Now moving on let's see that plant. In the **Greenhouse Management** tab, we can browse the **Composite** structure. As we expand the beds, you can see we have nested beds and individual plants.
>
> "Here is the 'Bonsai' we just added. When we select it, the right panel updates with its live data. This is the **Observer** pattern at work; the UI observes the plant. We can see its vitals and its current **State**, which is 'seed'.
>
> "Now, let's simulate time passing. By clicking 'Run Growth Tick', we use a **Greenhouse Iterator** to visit every plant in the composite and apply growth. You can see the plant's vitals changing in the log, additionally lets assign a staff member to track our new 'bonsai'plant.
>
> "Let's run a few more ticks. ... Okay, notice the log? The plant's state changed to 'Mature', and its 'Sale Readiness' is now 'True'. This state change was also *observed* by its corresponding `StockItem`, so it's now available for sale."
>
> **Flow 3: Staff & Plant Care (Command, Observer, Strategy)**
> 
> "Let's some more growth ticks, we now notice that the plant requires care. The plant's `WaterStrategy` determined it was thirsty and, as a Subject, it *notified* its **Observers**.
>
> "If we go to the **System Admin** tab and look at 'Staff Tasks', we can see 'Staff 101' is observing that plant, so a 'Water Plant' task appeared in their queue. This is the **Command** pattern. The request is an object in a queue.
>
> "When we process the next task, the command is executed, the plant is watered, and the task is removed from the queue.
>
> "Back in the **Greenhouse** tab, we can also change the plant's care **Strategy** at runtime. We'll select the Bonsai and change its Water Strategy from 'Sparse' to 'Frequent'. Now, this plant instance will use a different watering algorithm."
>
> "additionally we can manualy queue a water or fertilizing task for a selected plant and staff memeber, this will add the care request to the staff memebers pending task queue."
> 
> **Flow 4: Messaging & Sales (Mediator, Facade, Builder, Iterator)**
>
> "While we're here, let's use the **Messaging** tab. This system uses the **Mediator** pattern to decouple staff and customers. We'll send a message from 'Staff 101' to 'Customer 201' saying 'Your Bonsai is ready'.
>
> "Finally, let's sell that Bonsai. In the **Sales & Inventory** tab, the inventory list—which is populated by an **Inventory Iterator**—shows our Bonsai is listed as 'Available'.
>
> "In the 'sales' sub-tab, from the 'Select Item' dropdown, we'll add the 'Bonsai' to the order. This dropdown only shows items that are *actually* available for sale, thanks to the Observer and Iterator patterns working together.
>
> "Now, we'll also select 'Customer 201'.
>
> "When we click 'Process Payment', we are calling our **Sales Facade**. This one method call handles everything: it uses an **Order Builder** to create the order, tells the `PaymentProcessor` to charge the customer, and updates the `Inventory` to remove the item. As you can see, the order is logged, additionally if we check the inventory list and greenhouse, the Bonsai is gone."
>
> "That concludes the main simulation flow. As you can see, the patterns work together to create a decoupled and flexible system. Now, I'll pass it over to Zoe to discuss our documentation."

---

## 5. Code Documentation (2.5 Minutes)

* **Speaker:** Zoë
* **Driver:** Connor

#### 🕹️ [Connor's Cues]
* Switch from the GUI to the web browser showing the Doxygen HTML output.
* Navigate to a key class page, like `PlantInstance` or `SalesFacade`, as Zoë begins.
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
* "We also set up a GitHub Actions pipeline to automatically lint and test our code on every commit."

---

## 7. Conclusion & Q&A (2 Minutes)

* **Speaker:** Adriano
* **Driver:** Connor

#### 🕹️ [Connor's Cues]
* Switch from GitHub back to the presentation.
* Advance to the final slide (Slide 12).

#### slides
* **Slide 12: Thank You**
    * Title: Thank You
    * Message: Questions?

#### 🎤 Adriano's Speech (Conclusion)
> "Thank you, Bulelani and Zoë.
>
> In summary, our Plant Palace system successfully models a complex nursery using C++17 and object-oriented principles. By applying design patterns like **Facade**, **Composite**, **Observer**, and **Adapter**, we built a system that is flexible, maintainable, and meets all the project requirements.
>
> This project was a great experience in collaborative software development.
>
> Thank you for your time. We would now like to open the floor for any questions."
