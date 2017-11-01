# TheBestCS300Group

## Frupal Client

The HTML, CSS and javascript which runs on the user's web browser.

It currently only sends a simple json object consisting of:

```javascript
{
  "action": "nameOfAction",
  "name": "playerName"
}
```

## Frupal Server

The cgi script which receives json objects from the web page. It currently just returns exactly what it receives.

### CgiReader Class

A basic class used by the server to read in json from stdin. Returned with a getCommand() function.
