Thisted event import
==========

This module provide a feature and code to import events from third party service
into Thisted project.

## Requirements:
You have to know URI for third service.

## Configuration:
Enable module on @/admin/modules page.

Go to @/admin/config/ting/events_import admin configuration form.
Here you will have to bind third party service URI with existing Library node.
Create new node with type "xml_event_import (Xml event import)",
Fill title and URL field from "FEED" section, don't make any changes in "XPATH PARSER SETTINGS",
everything is configured by feature, if you have to make some changes in mapping, they should be made in
Feeds module configuration @/admin/structure/feeds/thisted, and DON'T FORGET to update feature after changes.
After node will be saved, import will run.

Take in mind, that third party service URI on node edit page should be same
as you entered on module configuration page.
