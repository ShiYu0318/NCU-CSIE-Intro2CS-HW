package hw.hw8;

import javafx.animation.KeyFrame;
import javafx.animation.Timeline;
import javafx.application.Application;
import javafx.beans.binding.Bindings;
import javafx.geometry.Insets;
import javafx.geometry.Pos;
import javafx.scene.Scene;
import javafx.scene.effect.Glow;
import javafx.scene.layout.*;
import javafx.scene.paint.*;
import javafx.scene.shape.*;
import javafx.scene.text.*;
import javafx.scene.transform.Rotate;
import javafx.stage.Stage;
import javafx.util.Duration;
import java.time.LocalTime;

public class A08_114502540 extends Application {

    private static final String C_BG_VOID  = "#000000";
    private static final String C_BG_PANEL = "#050508";
    private static final String C_BG_CARD  = "#0A0A14";
    private static final String C_CYAN     = "#00D4FF";
    private static final String C_BLUE     = "#0057FF";
    private static final String C_WHITE    = "#F5F5F7";
    private static final String C_GRAY     = "#8E8E93";
    private static final String C_BORDER   = "#1C1C2E";

    private ClockPane clockPane;
    private Text titleText;
    private Circle decorCircle;

    public static void main(String[] args) { launch(args); }

    @Override
    public void start(Stage stage) {
        BorderPane root = new BorderPane();
        root.setStyle("-fx-background-color: " + C_BG_VOID + ";");

        root.setTop(buildTitleSection());
        root.setLeft(buildLeftDecoration());
        root.setRight(buildRightDecoration());
        root.setCenter(buildCenterSection());
        root.setBottom(buildBottomSection());

        Scene scene = new Scene(root, 900, 650);

        titleText.styleProperty().bind(
                Bindings.concat(
                        "-fx-font-size: ",
                        scene.widthProperty().multiply(0.048).asString("%.0f"),
                        "px; -fx-font-weight: bold; -fx-fill: " + C_CYAN + ";"
                )
        );

        decorCircle.radiusProperty().bind(scene.widthProperty().multiply(0.06));

        stage.setMinWidth(600);
        stage.setMinHeight(450);
        stage.setTitle("AI 創意發表會 2026");
        stage.setScene(scene);
        stage.show();
    }

    @Override
    public void stop() {
        if (clockPane != null) clockPane.stopClock();
    }

    private StackPane buildTitleSection() {
        LinearGradient bgGrad = new LinearGradient(
                0, 0, 1, 0, true, CycleMethod.NO_CYCLE,
                new Stop(0.0, Color.web("#000000")),
                new Stop(0.5, Color.web("#03030E")),
                new Stop(1.0, Color.web("#000814"))
        );
        Rectangle titleRect = new Rectangle();
        titleRect.setHeight(120);
        titleRect.setFill(bgGrad);

        Rectangle neonEdge = new Rectangle();
        neonEdge.setHeight(2);
        neonEdge.setFill(new LinearGradient(
                0, 0, 1, 0, true, CycleMethod.NO_CYCLE,
                new Stop(0.0, Color.TRANSPARENT),
                new Stop(0.25, Color.web(C_CYAN)),
                new Stop(0.75, Color.web(C_BLUE)),
                new Stop(1.0, Color.TRANSPARENT)
        ));

        titleText = new Text("AI 創意發表會");
        titleText.setFill(Color.web(C_CYAN));
        titleText.setFont(Font.font("System", FontWeight.BOLD, 40));
        titleText.setEffect(new Glow(0.5));

        Text subtitleText = new Text("AI Creative Presentation 2026");
        subtitleText.setFill(Color.web(C_GRAY));
        subtitleText.setFont(Font.font("System", 15));

        VBox titleVBox = new VBox(6, titleText, subtitleText);
        titleVBox.setAlignment(Pos.CENTER_LEFT);

        Polygon starPolygon = new Polygon(
                50.0, 10.0, 59.0, 37.0, 88.0, 38.0, 65.0, 55.0, 74.0, 82.0,
                50.0, 66.0, 27.0, 82.0, 35.0, 55.0, 12.0, 38.0, 41.0, 37.0
        );
        starPolygon.setFill(Color.web("#FFD60A"));
        starPolygon.setStroke(Color.web("#FFD60A", 0.25));
        starPolygon.setStrokeWidth(1);
        starPolygon.setOpacity(0.88);
        starPolygon.getTransforms().add(new Rotate(15, 50, 50));
        starPolygon.setStyle("-fx-effect: dropshadow(gaussian, #FFD60A66, 14, 0, 0, 0);");

        HBox titleHBox = new HBox();
        titleHBox.setAlignment(Pos.CENTER_LEFT);
        titleHBox.setPadding(new Insets(20, 24, 20, 24));
        titleHBox.getChildren().addAll(titleVBox, starPolygon);
        HBox.setHgrow(titleVBox, Priority.ALWAYS);

        StackPane titleSection = new StackPane();
        titleSection.setAlignment(Pos.TOP_LEFT);
        titleRect.widthProperty().bind(titleSection.widthProperty());
        neonEdge.widthProperty().bind(titleSection.widthProperty());
        StackPane.setAlignment(neonEdge, Pos.BOTTOM_CENTER);
        titleSection.getChildren().addAll(titleRect, titleHBox, neonEdge);

        return titleSection;
    }

    private HBox buildCenterSection() {
        VBox leftCol = new VBox(14);
        leftCol.setPadding(new Insets(10));
        leftCol.setAlignment(Pos.CENTER);
        leftCol.getChildren().addAll(
                new EventCard("活動日期", "2026 年 5 月 7 日"),
                new EventCard("活動地點", "工程五館 A207 教室"),
                new EventCard("主辦單位", "NCU CSIE")
        );

        clockPane = new ClockPane();
        clockPane.setStyle("-fx-effect: dropshadow(gaussian, #00D4FF44, 32, 0.05, 0, 0);");

        VBox rightCol = buildRightColumn();

        HBox center = new HBox(20);
        center.setPadding(new Insets(20));
        center.setAlignment(Pos.CENTER);
        center.getChildren().addAll(leftCol, clockPane, rightCol);
        HBox.setHgrow(leftCol, Priority.ALWAYS);
        HBox.setHgrow(rightCol, Priority.ALWAYS);

        return center;
    }

    private VBox buildRightColumn() {
        Polygon hexPolygon = new Polygon(
                70.0, 20.0, 113.0, 45.0, 113.0, 95.0,
                70.0, 120.0, 27.0, 95.0, 27.0, 45.0
        );
        hexPolygon.setFill(Color.TRANSPARENT);
        hexPolygon.setStroke(Color.web(C_CYAN));
        hexPolygon.setStrokeWidth(1.5);
        hexPolygon.getTransforms().add(new Rotate(15, 70, 70));
        hexPolygon.setStyle("-fx-effect: dropshadow(gaussian, #00D4FF55, 12, 0, 0, 0);");

        decorCircle = new Circle(0);
        decorCircle.setFill(Color.TRANSPARENT);
        decorCircle.setStroke(Color.web(C_BLUE));
        decorCircle.setStrokeWidth(1.5);
        decorCircle.setStyle("-fx-effect: dropshadow(gaussian, #0057FF55, 12, 0, 0, 0);");

        Text aiText = new Text("AI");
        aiText.setFill(Color.web(C_CYAN));
        aiText.setFont(Font.font("System", FontWeight.BOLD, 42));
        aiText.getTransforms().add(new Rotate(-20, 0, 0));
        aiText.setEffect(new Glow(0.6));

        VBox col = new VBox(16);
        col.setAlignment(Pos.CENTER);
        col.setPadding(new Insets(10));
        col.getChildren().addAll(hexPolygon, decorCircle, aiText);

        return col;
    }

    private HBox buildBottomSection() {
        Text regText = new Text("— 報名截止 2026/04/30 —");
        regText.setFill(Color.web(C_GRAY));
        regText.setFont(Font.font("System", FontPosture.ITALIC, 13));

        Polygon arrowPolygon = new Polygon(
                0.0, 0.0, 20.0, 0.0, 30.0, 12.0,
                20.0, 24.0, 0.0, 24.0, 10.0, 12.0
        );
        arrowPolygon.setFill(Color.web(C_CYAN));
        arrowPolygon.setStyle("-fx-effect: dropshadow(gaussian, #00D4FF88, 8, 0, 0, 0);");

        Text freeText = new Text("免費入場  Free Admission");
        freeText.setFill(Color.web(C_WHITE));
        freeText.setFont(Font.font("System", FontWeight.BOLD, 14));

        Rectangle pillRect = new Rectangle(175, 40);
        pillRect.setArcWidth(30);
        pillRect.setArcHeight(30);
        pillRect.setFill(Color.web("#040410"));
        pillRect.setStroke(Color.web(C_CYAN));
        pillRect.setStrokeWidth(1.5);

        Text registerText = new Text("立即報名");
        registerText.setFill(Color.web(C_CYAN));
        registerText.setFont(Font.font("System", FontWeight.BOLD, 14));

        StackPane pillButton = new StackPane(pillRect, registerText);
        pillButton.setAlignment(Pos.CENTER);
        pillButton.setStyle("-fx-effect: dropshadow(gaussian, #00D4FF44, 18, 0, 0, 0);");

        HBox bottom = new HBox(20);
        bottom.setAlignment(Pos.CENTER);
        bottom.getChildren().addAll(regText, arrowPolygon, freeText, pillButton);
        bottom.setStyle(
                "-fx-background-color: #02020A;" +
                "-fx-padding: 14 20 14 20;" +
                "-fx-border-color: #00D4FF22;" +
                "-fx-border-width: 1 0 0 0;"
        );

        return bottom;
    }

    private VBox buildLeftDecoration() {
        VBox decor = new VBox(14);
        decor.setAlignment(Pos.CENTER);
        decor.setStyle("-fx-background-color: #02020A; -fx-padding: 24 10 24 10;");
        decor.setPrefWidth(62);

        double[] radii = {10, 5, 10, 5};
        double[] opacities = {1.0, 0.45, 1.0, 0.45};
        for (int i = 0; i < 4; i++) {
            Circle c = new Circle(radii[i]);
            c.setFill(Color.web(C_CYAN));
            c.setOpacity(opacities[i]);
            c.setStyle("-fx-effect: dropshadow(gaussian, #00D4FFBB, 10, 0.3, 0, 0);");
            decor.getChildren().add(c);
        }

        Rectangle bar = new Rectangle(2, 200);
        bar.setFill(new LinearGradient(
                0, 0, 0, 1, true, CycleMethod.NO_CYCLE,
                new Stop(0, Color.web(C_CYAN)),
                new Stop(1, Color.TRANSPARENT)
        ));
        bar.setArcWidth(2);
        bar.setArcHeight(2);
        bar.setStyle("-fx-effect: dropshadow(gaussian, #00D4FF77, 6, 0, 0, 0);");
        decor.getChildren().add(bar);

        return decor;
    }

    private VBox buildRightDecoration() {
        VBox decor = new VBox(11);
        decor.setAlignment(Pos.CENTER);
        decor.setStyle("-fx-background-color: #02020A; -fx-padding: 24 10 24 10;");
        decor.setPrefWidth(62);

        String[] letters = {"A", "I", "2", "0", "2", "6"};
        double[] rotations = {10, -10, 10, -10, 10, -10};
        for (int i = 0; i < letters.length; i++) {
            Text t = new Text(letters[i]);
            t.setFill(Color.web(i % 2 == 0 ? C_CYAN : C_BLUE));
            t.setFont(Font.font("System", FontWeight.BOLD, 18));
            t.getTransforms().add(new Rotate(rotations[i], 0, 0));
            if (i % 2 == 0) {
                t.setStyle("-fx-effect: dropshadow(gaussian, #00D4FF99, 8, 0.2, 0, 0);");
            }
            decor.getChildren().add(t);
        }

        Rectangle bar = new Rectangle(2, 200);
        bar.setFill(new LinearGradient(
                0, 0, 0, 1, true, CycleMethod.NO_CYCLE,
                new Stop(0, Color.web(C_BLUE)),
                new Stop(1, Color.TRANSPARENT)
        ));
        bar.setArcWidth(2);
        bar.setArcHeight(2);
        bar.setStyle("-fx-effect: dropshadow(gaussian, #0057FF77, 6, 0, 0, 0);");
        decor.getChildren().add(bar);

        return decor;
    }

    static class ClockPane extends Pane {
        private static final double CX = 100, CY = 100, RADIUS = 90;

        private final Circle clockFace, centerDot;
        private final Line[] hourTicks;
        private final Line hourHand, minuteHand, secondHand;
        private final Text[] hourLabels;
        private final Timeline timeline;

        ClockPane() {
            setPrefSize(200, 200);

            clockFace = new Circle(CX, CY, RADIUS);
            clockFace.setFill(new RadialGradient(
                    0, 0, CX, CY, RADIUS, false, CycleMethod.NO_CYCLE,
                    new Stop(0.0, Color.web("#0B0B1A")),
                    new Stop(0.7, Color.web("#060610")),
                    new Stop(1.0, Color.web("#000005"))
            ));
            clockFace.setStroke(Color.web("#00D4FF"));
            clockFace.setStrokeWidth(2);
            clockFace.setStyle("-fx-effect: dropshadow(gaussian, #00D4FF55, 20, 0.1, 0, 0);");

            hourTicks = new Line[12];
            for (int i = 0; i < 12; i++) {
                double angle = Math.toRadians(i * 30 - 90);
                double innerR = (i % 3 == 0) ? RADIUS - 16 : RADIUS - 9;
                hourTicks[i] = new Line(
                        CX + innerR * Math.cos(angle), CY + innerR * Math.sin(angle),
                        CX + RADIUS * Math.cos(angle), CY + RADIUS * Math.sin(angle)
                );
                hourTicks[i].setStroke(Color.web(i % 3 == 0 ? "#00D4FF" : "#1A2A3A"));
                hourTicks[i].setStrokeWidth(i % 3 == 0 ? 2.5 : 1);
            }

            hourHand = new Line(CX, CY, CX, CY);
            hourHand.setStroke(Color.web("#F5F5F7"));
            hourHand.setStrokeWidth(4);
            hourHand.setStrokeLineCap(StrokeLineCap.ROUND);

            minuteHand = new Line(CX, CY, CX, CY);
            minuteHand.setStroke(Color.web("#00D4FF"));
            minuteHand.setStrokeWidth(2.5);
            minuteHand.setStrokeLineCap(StrokeLineCap.ROUND);
            minuteHand.setStyle("-fx-effect: dropshadow(gaussian, #00D4FFBB, 8, 0.3, 0, 0);");

            secondHand = new Line(CX, CY, CX, CY);
            secondHand.setStroke(Color.web("#FF3B30"));
            secondHand.setStrokeWidth(1.5);
            secondHand.setStrokeLineCap(StrokeLineCap.ROUND);

            centerDot = new Circle(CX, CY, 5);
            centerDot.setFill(Color.web("#FF3B30"));
            centerDot.setStyle("-fx-effect: dropshadow(gaussian, #FF3B3099, 6, 0.3, 0, 0);");

            int[] labelHours = {12, 3, 6, 9};
            double[] labelAngles = {-90, 0, 90, 180};
            hourLabels = new Text[4];
            for (int i = 0; i < 4; i++) {
                double angle = Math.toRadians(labelAngles[i]);
                hourLabels[i] = new Text(
                        CX + (RADIUS - 27) * Math.cos(angle) - 6,
                        CY + (RADIUS - 27) * Math.sin(angle) + 5,
                        String.valueOf(labelHours[i])
                );
                hourLabels[i].setFill(Color.web("#8E8E93"));
                hourLabels[i].setFont(Font.font("System", FontWeight.BOLD, 11));
            }

            getChildren().add(clockFace);
            for (Line t : hourTicks) getChildren().add(t);
            for (Text l : hourLabels) getChildren().add(l);
            getChildren().addAll(hourHand, minuteHand, secondHand, centerDot);

            paintClock();

            timeline = new Timeline(new KeyFrame(Duration.seconds(1), e -> paintClock()));
            timeline.setCycleCount(Timeline.INDEFINITE);
            timeline.play();
        }

        private void paintClock() {
            LocalTime now = LocalTime.now();
            int hour = now.getHour() % 12;
            int minute = now.getMinute();
            int second = now.getSecond();

            double secondAngle = Math.toRadians(second * 6.0 - 90);
            double minuteAngle = Math.toRadians(minute * 6.0 + second * 0.1 - 90);
            double hourAngle = Math.toRadians(hour * 30.0 + minute * 0.5 - 90);

            double hourLen = RADIUS * 0.55;
            double minuteLen = RADIUS * 0.75;
            double secondLen = RADIUS * 0.85;

            hourHand.setEndX(CX + hourLen * Math.cos(hourAngle));
            hourHand.setEndY(CY + hourLen * Math.sin(hourAngle));
            minuteHand.setEndX(CX + minuteLen * Math.cos(minuteAngle));
            minuteHand.setEndY(CY + minuteLen * Math.sin(minuteAngle));
            secondHand.setEndX(CX + secondLen * Math.cos(secondAngle));
            secondHand.setEndY(CY + secondLen * Math.sin(secondAngle));
        }

        void stopClock() { timeline.stop(); }
    }

    static class EventCard extends VBox {
        EventCard(String label, String value) {
            setSpacing(4);
            setAlignment(Pos.CENTER_LEFT);
            setStyle(
                    "-fx-background-color: #0A0A14;" +
                    "-fx-background-radius: 14;" +
                    "-fx-border-color: #1C1C2E;" +
                    "-fx-border-width: 1;" +
                    "-fx-border-radius: 14;" +
                    "-fx-padding: 14 16 14 16;" +
                    "-fx-effect: dropshadow(gaussian, #00D4FF1A, 20, 0, 0, 6);"
            );

            Rectangle badge = new Rectangle(3, 52);
            badge.setFill(new LinearGradient(
                    0, 0, 0, 1, true, CycleMethod.NO_CYCLE,
                    new Stop(0, Color.web("#00D4FF")),
                    new Stop(1, Color.web("#0057FF"))
            ));
            badge.setArcWidth(3);
            badge.setArcHeight(3);

            Text labelText = new Text(label);
            labelText.setFill(Color.web("#8E8E93"));
            labelText.setFont(Font.font("System", FontWeight.BOLD, 12));

            Text valueText = new Text(value);
            valueText.setFill(Color.web("#F5F5F7"));
            valueText.setFont(Font.font("System", FontWeight.BOLD, 15));

            VBox textVBox = new VBox(4, labelText, valueText);
            textVBox.setAlignment(Pos.CENTER_LEFT);

            HBox row = new HBox(12, badge, textVBox);
            row.setAlignment(Pos.CENTER_LEFT);

            getChildren().add(row);
        }
    }
}
