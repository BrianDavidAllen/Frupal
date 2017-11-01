# TheBestCS300Group

## Frupal Client

The HTML, CSS and javascript which runs on the user's web browser.

It currently only sends a simple json object consisting of:

```javascript
{
  "name": "playerName",
  "action": "nameOfAction"
}
```

## Frupal Server

The cgi script which receives json objects from the web page. It currently just returns exactly what it receives.
