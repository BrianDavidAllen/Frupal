// Frupal web client javascript

var data; //Javascript object holding all our game data
var tileSize = 20;
var jsonVisible = false;

//Button to display the raw json. Hide by default to speed up page reload.
var showJson = function() {
    var rawJsonElement = document.getElementById("rawJson");
    rawJsonElement.innerHTML = "<pre>" + JSON.stringify(data, null, 2) + "</pre>";
}

function Game() {


    //This function gets called on every key press, and if a valid key is found, sendCommand() is called with the corresponding command.
    this.handleKeys = function(event) {
        var code = event.keyCode;
        var command;
        console.log("Key pressed");
        if(code == 37) //Left
            command = "left";
        else if(code == 38) //Up
            command = "up";
        else if(code == 39) //Right
            command = "right";
        else if(code == 40) //Down
            command = "down";
        else if(code == 32) //Spacebar
            command = "space";
        else
            return;  //Ignore if some other key is pressed
        
        this.sendCommand(command);
    }

    //Redraw all the updatable parts of the screen with new data
    this.redraw = function() {
        console.log("Redrawing.");

        //Print the log text
        var logElement = document.getElementById("log");
        logElement.innerHTML = data.log;

        //Print hero position
        var heroPosition = document.getElementById("coordinates");
        heroPosition.innerHTML = "The hero is at " + data.hero.x + " Grovnick East and " +  data.hero.y + " Grovnick North from the Origin";
 
        //Redraw the tiles
        var mapElement = document.getElementById("map");
        var toAdd = "";
        var numberOfTiles = data.map.grovnicks.length;
        console.log("Loading " + numberOfTiles + " tiles.");
        for(var i = 0; i < data.map.grovnicks.length; ++i) {
            var tile = data.map.grovnicks[i];
            toAdd += "<div class='tile type"
                + tile.terrian + " "
                + tile.Visible
                + "' style='left:"
                + (tile.x*tileSize)
                + "px;top:"
                + (tile.y*tileSize)
                + "px'></div>";
        }
        mapElement.innerHTML = toAdd;

        //Redraw the player
        var playerElement = document.getElementById("player");
        playerElement.style.left = data.hero.x * tileSize + "px";
        playerElement.style.top = data.hero.y * tileSize + "px";
        if(jsonVisible) {
            showJson();
        }
    }

    //Send the user's command to the server via ajax call
    this.sendCommand = function(command){
        console.log("Sending comand: " + command);

        var self = this;
        var req = new XMLHttpRequest();
        req.onreadystatechange = function() {
            if(this.readyState == 4 && this.status == 200) {
                data = JSON.parse(req.responseText);
                self.redraw();
            }
        };

        req.open("POST", "frupal.cgi");
        req.setRequestHeader("Content-Type", "application/json");
        req.send(JSON.stringify({"command":command}));
        return false;
    };
}
