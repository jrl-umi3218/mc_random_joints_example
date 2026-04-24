## Sample controller to show how to use mc_rtc without the QP

This will:
- Generate random joint positions (within the robot kinematics limits)
- Track them with a posture task
- or disable the QP entirely and set the generated target as output directly

See the following demo video:

https://github.com/user-attachments/assets/e5d8b8b3-15e2-4e8b-aad3-aab097afce93


## How to use
### With nix

```
nix develop github:jrl-umi3218/mc_random_joints_example
mc-rtc-magnum &
mc_rtc_ticker
```
