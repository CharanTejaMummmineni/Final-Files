import cv2
from cvzone.HandTrackingModule import HandDetector
from cvzone.SerialModule import SerialObject

hand = cv2.VideoCapture(0)
detection = HandDetector(detectionCon=0.8, maxHands=1)
arduino = SerialObject()

while True:
    success, img = hand.read()
    req, img = detection.findHands(img)

    if req:
        tracking = req[0]
        lmlist = tracking["lmList"]
        bbox = tracking["bbox"]
        centerPoint = tracking['center']
        handType = tracking["type"]
        if lmlist:
            fingers = detection.fingersUp(tracking)
            print(fingers)
            arduino.sendData(fingers)

    cv2.imshow("Frame1", img)
    key = cv2.waitKey(1)
    if key == 27:
        cv2.destroyAllWindows()
        break